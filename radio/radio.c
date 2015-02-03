#include <cc1110.h>
#include "cc1110-ext.h"
#include <stdint.h>
#include <stdio.h>

#define MAXLEN 0xFF

//char str[1];
char __xdata at 0xfe00 packet[MAXLEN] ;
//static const char banner[] = {'\r', '\n', 'H', 'E', 'L', 'L', 'O', '\r', '\n'};

//#define MAXLEN 0xFF
//char __xdata at 0xfe00 packet[MAXLEN] ;

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

void main() {
  //unsigned char len=16, i=0;
  unsigned char n=0, i=0, len=16, ch;
  uint8_t lastRssi, lastLqi;

  // configure port 0 pin 0 as output and set low
  P0DIR |= 0x01;
  P0_0 = 0;

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
  FREND0 = 0x10; // Front end RX configuration.
  MCSM0 = 0x18; // Main Radio Control State Machine configuration.
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

  PERCFG = (PERCFG & ~PERCFG_U0CFG) | PERCFG_U1CFG;
 
  P0SEL |= 0x08 | 0x04;
  U0CSR |= 0x80 | 0x40;
  U0GCR = 13;
  U0BAUD = 59;
  URX0IF = 0;

  //n = 0;
  //  while(n < sizeof(banner))
  // cons_putc(banner[n++]);
  cons_putsln("\r\nHELLO");

  while(1) { 
    //1-out the buffer.
    
    for(i=0;i<MAXLEN;i++)
      packet[i]=0xFF;
    i=0;
    
    //Disable interrupts.
    RFTXRXIE=0;
    
    //idle a bit.
    RFST=RFST_SIDLE;
    while(MARCSTATE!=MARC_STATE_IDLE);
    
    //Begin to receive.
    RFST=RFST_SRX;
    while(MARCSTATE!=MARC_STATE_RX);
    //len=16;
    /*
    //Fixed length
    
    while(i<PKTLEN) {
      while(!RFTXRXIF); //Wait for byte to be ready.
      RFTXRXIF=0;      //Clear the flag.
      packet[i++]=RFD; //Grab the next byte.
    }
    
    RFST = RFST_SIDLE; //End receive.
    */

    if(PKTCTRL0&1){
      //auto length
      while(i<len+1){ //len+3 if status is appended.
	while(!RFTXRXIF); //Wait for byte to be ready.
	RFTXRXIF=0;     //Clear the flag.
	
	packet[i++]=RFD; //Grab the next byte.
	len=packet[0];   //First byte of the packet is the length.
      }
    }else{
      //Fixed length
      packet[i++]=PKTLEN;
      while(i<PKTLEN){
	while(!RFTXRXIF); //Wait for byte to be ready.
	RFTXRXIF=0;      //Clear the flag.
	
	packet[i++]=RFD; //Grab the next byte.
      }
    }
    lastRssi = RSSI;
    lastLqi = LQI;
    RFST = RFST_SIDLE; //End receive.
    while(MARCSTATE!=MARC_STATE_IDLE);
    // print out the packet to uart
    // print payload size
    
    // flash the LED on P0_0
    P0_0 = 1;
    delay(25);
    P0_0 = 0;

    cons_putsln("New Packet:");
    cons_puthex8(packet[0]);
    cons_putsln("");
    // print network id (panid)
    cons_puthex8(packet[1]);
    cons_puthex8(packet[2]);
    cons_putsln("");
    
    // print packet data
    n = 3;
    while(n < sizeof(packet)) {
      ch = packet[n++];
      if (ch != 0xFF) 
	//cons_puthex8(ch);
	cons_putc(ch);
      //sprintf(str, "%c", packet[n++]);
      //cons_putc(str[0]);
    }
    cons_putsln("");
    cons_puts("RSSI: ");
    cons_puthex8(lastRssi);
    cons_puts(" LQI: ");
    cons_puthex8(lastLqi);
    cons_putsln("");
    //cons_putc('\n');
  }
}
