#include <cc1110.h>
#include "cc1110-ext.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#define MAXLEN 0xFF

void rftxrx_isr(void) __interrupt RFTXRX_VECTOR;
static uint8_t packet_index;
static __xdata uint8_t packet[MAXLEN];

uint8_t preamble[] = {0x0E, 0x5A, 0xA5};
unsigned int rssi_offset;

void delay(int msec) {
  int i,j;
  
  for (i=0; i<msec; i++)
    for (j=0; j<1000; j++);
}

char nibble_to_char(uint8_t nibble) {
  if (nibble < 0xA)
    return nibble + '0';
  return nibble - 0xA + 'A';
}

void cons_putc(uint8_t ch) {
  U0DBUF = ch;
  while(!(U0CSR & U0CSR_TX_BYTE)); // wait for byte to be transmitted                                                                     
  U0CSR &= ~U0CSR_TX_BYTE;         // Clear transmit byte status                                                                          
}

void cons_puts(const char *s)
{
  while(0 != *s)
    cons_putc((uint8_t)(*s++));
}

void cons_putsln(const char *s)
{
  cons_puts(s);
  cons_puts("\r\n");
}

void cons_puthex8(uint8_t h) {
  cons_putc(nibble_to_char((h & 0xF0)>>4));
  cons_putc(nibble_to_char(h & 0x0F));
}

void cons_puthex16(uint16_t h)
{
  cons_putc(nibble_to_char((h & 0xF000)>>12));
  cons_putc(nibble_to_char((h & 0x0F00)>>8));
  cons_putc(nibble_to_char((h & 0x00F0)>>4));
  cons_putc(nibble_to_char(h & 0x000F));
}

int convert_rssi(uint8_t rssi_raw) {
  int rssi_dec = (int) rssi_raw;

  if (rssi_dec < 128) {
    return (rssi_dec / 2) - rssi_offset;
  }
  else {
    return ((rssi_dec - 256) / 2) - rssi_offset;
  }
}

void switchchange(int *prevstate) {
  if (P1_6 != *prevstate) {
    P1_3 ^= 1;
    delay(100); // crap debounce
  }
  *prevstate = P1_6;
}

void rftxrx_isr(void) __interrupt RFTXRX_VECTOR {
  switch (MARCSTATE) {
    case MARC_STATE_RX:
      // receive byte
      packet[packet_index++] = RFD;
      break;
    case MARC_STATE_TX:
      // transmit byte
      RFD = packet[packet_index++];
      break;
  } 
}

void sendpacket() {
  cons_putsln("Start TX");
  // use timer 3 to delay tx to allow time to switch from tx to rx
  T3CTL=0xDC;
  T3OVFIF=0; 
  while (!T3OVFIF);
  T3CTL=0;

  // flash the LED on P0_0
  //P0_0 = 1;
  //delay(25);
  //P0_0 = 0;

  packet_index = 0;
  RFST = RFST_STX;
  while (MARCSTATE != MARC_STATE_TX);
  // tx happens here
  while (MARCSTATE != MARC_STATE_IDLE);
  RFIF=0;
  cons_putsln("Done TX");
}

void sendllap(char *m, int count) {
  int i=0;
  // sends an llap message count times
  // put packet header in
  memcpy(packet, preamble, sizeof(preamble)/sizeof(uint8_t));
  // put packet data in
  memcpy(packet+sizeof(preamble)/sizeof(uint8_t), m, 12);
  // send it!
  for (i=0; i<count; i++)
    sendpacket();
}

void getpacket() {
  char llapmsg[13];
  if (RFIF & RFIF_IRQ_DONE) {
    unsigned int n = 0;
    //while(MARCSTATE!=MARC_STATE_IDLE);
    RFIF = 0;

    // flash the LED on P0_0
    //P0_0 = 1;
    //delay(25);
    //P0_0 = 0;

    cons_putsln("New Packet:");
    // print packet size (first byte)
    cons_puthex8(packet[0]);
    cons_putsln("");
    // print network id (panid)
    cons_puthex8(packet[1]);
    cons_puthex8(packet[2]);
    cons_putsln("");
  
    // print packet data
    n = 3;
    while(n < (packet[0]+1)) {
      llapmsg[n-3] = packet[n];
      cons_putc(packet[n++]);
    }
    llapmsg[12] = '\0';
    
    cons_putsln("");
    cons_puts("RSSI: ");
    cons_puthex8(RSSI);

    cons_puts(" LQI: ");
    cons_puthex8(LQI);
    cons_putsln("");

    if (PKTSTATUS & 0x80) {
      cons_putsln("CRC: OK");
    }
    else {
      cons_putsln("CRC: Fail");
    }
    
    // process llap message if it is one and its for us
    if (strncmp(llapmsg, "aTR", 3) == 0) {
      // seems like a valid llap message
      if (strncmp(llapmsg+3, "LEDON----", 9) == 0) {
	sendllap(llapmsg, 1);
	P1_3 = 1; // turn on
      } else if (strncmp(llapmsg+3, "LEDOFF---", 9) == 0) {
	sendllap(llapmsg, 1);
	P1_3 = 0; // turn off
      } else if (strncmp(llapmsg+3, "HELLO----", 9) == 0) {
	// ping
	sendllap(llapmsg, 1);
      } else if (strncmp(llapmsg+3, "REBOOT---", 9) == 0) {
	// soft reboot to start of code
	sendllap(llapmsg, 1);
	__asm LCALL 0x0 __endasm;
      } else if (strncmp(llapmsg+3, "LED------", 9) == 0) {
	// send led current state
	if (P1_3 == 0) {
	  sendllap("aTRLEDOFF---", 1);
	} else {
	  sendllap("aTRLEDON----", 1);
	}
      }
    }
  }
  if (MARCSTATE != MARC_STATE_RX) {
    packet_index = 0;
    RFST = RFST_SRX;
    while (MARCSTATE != MARC_STATE_RX);
    cons_putsln("Waiting to receive...");
  }
}

void radio_init(void) {
  // clock init
  // Turn both high speed oscillators on
  SLEEP &= ~SLEEP_OSC_PD;
  // Wait until xtal oscillator is stable
  while( !(SLEEP & SLEEP_XOSC_S) ); 
  
/*  
  // Select xtal osc, 26 MHz
  // For v1.4 and earlier xrf
  CLKCON = 
    (CLKCON & ~(CLKCON_CLKSPD | CLKCON_OSC))
    | CLKSPD_DIV_1;
*/ 
  
  // Select xtal osc, 24 MHz
  // For v1.5+ XRF
  CLKCON = 
    (CLKCON & ~(CLKCON_CLKSPD | CLKCON_OSC))
    | CLKSPD_DIV_2;
  
  // Wait for change to take effect
  while (CLKCON & CLKCON_OSC); 
  // Turn off the RC osc.
  SLEEP |= SLEEP_OSC_PD; 

  // radio init
  RFST=RFST_SIDLE; // enter idle state

  FREQ0 = 0x24;
  FREQ1 = 0x2D;
  FREQ2 = 0x24;
  PA_TABLE0 = 0xC2;
  FSCTRL1 = 0x0C; // FSCTRL1 Frequency Synthesizer Control 
  MDMCFG4 = 0x1D; // MDMCFG4 Modem configuration 
  MDMCFG3 = 0x55; // MDMCFG3 Modem Configuration 
  MDMCFG2 = 0x13; // MDMCFG2 Modem Configuration 
  DEVIATN = 0x63; // DEVIATN Modem Deviation Setting 
  FREND1 = 0xB6; // FREND1 Front End RX Configuration 
  FOCCFG = 0x1D; // FOCCFG Frequency Offset Compensation Configuration 
  BSCFG = 0x1C; // BSCFG Bit Synchronization Configuration 
  AGCCTRL2 = 0xC7; // AGCCTRL2 AGC Control 
  AGCCTRL1 = 0x00; // AGCCTRL1 AGC Control 
  AGCCTRL0 = 0xB0; // AGCCTRL0 AGC Control 
  FSCAL3 = 0xEA; // FSCAL3 Frequency Synthesizer Calibration 
  FSCTRL0 = 0x00; // Frequency synthesizer control.
  FREND0 = 0x10; // Front end TX configuration.
  MCSM0 = 0x18; // Main Radio Control State Machine configuration.
  FSCAL3 = 0xEA;
  FSCAL2 = 0x2A;
  FSCAL1 = 0x00; // Frequency synthesizer calibration.
  FSCAL0 = 0x1F; // Frequency synthesizer calibration.
  TEST2 = 0x88; // Various test settings.
  TEST1 = 0x31; // Various test settings.
  TEST0 = 0x09; // Various test settings.
  //MDMCFG1 = 0x22; // default setting??? prob for 26 MHz
  //MDMCFG0 = 0xF8; // default setting??? prob for 26 MHz
  MDMCFG1 = 0x23; // calc for 24 MHz
  MDMCFG0 = 0x11; // calc for 24 MHz
  CHANNR = 0x00;
  MCSM1 = 0x30; // Main Radio Control State Machine configuration.
  PKTCTRL1 = 0x04; // Packet automation control.
  PKTCTRL0 = 0x45; // Packet automation control. Data whitening on.
  ADDR = 0x00; // Device address. Not used.
  PKTLEN = 0x0F;
  rssi_offset = 77;
  RFIF = 0;
  packet_index = 0;
  //enable interrupts.
  RFTXRXIF=0;
  RFTXRXIE=1;

  //go to idle state
  RFST=RFST_SIDLE;
  while(MARCSTATE!=MARC_STATE_IDLE);
  cons_putsln("Radio Started");
}

void main() {
  //unsigned char i=0; //, dotx=0;
  int swstate;
  
  // uart0 config
  PERCFG = (PERCFG & ~PERCFG_U0CFG) | PERCFG_U1CFG;
  P0SEL |= 0x08 | 0x04;
  U0CSR |= 0x80 | 0x40;
  // 115200
  U0GCR = 13;
  U0BAUD = 59;
  URX0IF = 0;

  // configure port 1 pin 3
  P1DIR |= 0x08;
  P1_3 = 0;

  // pin 6 on port 1 is input for manual switch, get initial state
  swstate = P1_6;

  radio_init();

  // enable interrupts globally
  F1 = 1;
  EA = 1;

  // send bootup message 5 times
  sendllap("aTRSTARTING-", 5);

  while(1) {
    // rx forever
    getpacket();
    // check input state
    switchchange(&swstate);
  }
}
