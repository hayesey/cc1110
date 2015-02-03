const RF_SETTINGS __code rfSettings[] = {
#if clkfreq == 26
  //**************************************************
  // Data rate 1
  //**************************************************
  // Deviation = 126.953125 
  // Base frequency = 868.299866 
  // Carrier frequency = 868.299866 
  // Channel number = 0 
  // Carrier frequency = 868.299866 
  // Modulated = true 
  // Modulation format = GFSK 
  // Manchester enable = false 
  // Sync word qualifier mode = 30/32 sync word bits detected 
  // Preamble count = 4 
  // Channel spacing = 199.951172 
  // Carrier frequency = 868.299866 
  // Data rate = 249.939 
  // RX filter BW = 541.666667 
  // = Random TX mode 
  // Length config = Infinite packet length mode 
  // CRC enable = false 
  // Packet length = 255 
  // Device address = 0 
  // Address config = No address check 
  // = false 
  // PA ramping = false 
  // TX power = 0 
  {
    0x12, // FSCTRL1 Frequency Synthesizer Control 
    0x2D, // MDMCFG4 Modem configuration 
    0x3B, // MDMCFG3 Modem Configuration 
    0x13, // MDMCFG2 Modem Configuration 
    0x62, // DEVIATN Modem Deviation Setting 
    0xB6, // FREND1 Front End RX Configuration 
    0x1D, // FOCCFG Frequency Offset Compensation Configuration 
    0x1C, // BSCFG Bit Synchronization Configuration 
    0xC7, // AGCCTRL2 AGC Control 
    0x00, // AGCCTRL1 AGC Control 
    0xB0, // AGCCTRL0 AGC Control 
    0xEA // FSCAL3 Frequency Synthesizer Calibration 
  },


  //**************************************************
  // Data rate 2
  //**************************************************
  // Deviation = 19.042969 
  // Base frequency = 868.299866 
  // Carrier frequency = 868.299866 
  // Channel number = 0 
  // Carrier frequency = 868.299866 
  // Modulated = true 
  // Modulation format = GFSK 
  // Manchester enable = false 
  // Sync word qualifier mode = 30/32 sync word bits detected 
  // Preamble count = 4 
  // Channel spacing = 199.951172 
  // Carrier frequency = 868.299866 
  // Data rate = 38.3835 
  // RX filter BW = 101.562500 
  // = Random TX mode 
  // Length config = Infinite packet length mode 
  // CRC enable = false 
  // Packet length = 255 
  // Device address = 0 
  // Address config = No address check 
  // = false 
  // PA ramping = false 
  // TX power = 0 
  {
    0x06, // FSCTRL1 Frequency Synthesizer Control 
    0xCA, // MDMCFG4 Modem configuration 
    0x83, // MDMCFG3 Modem Configuration 
    0x13, // MDMCFG2 Modem Configuration 
    0x34, // DEVIATN Modem Deviation Setting 
    0xB6, // FREND1 Front End RX Configuration 
    0x1D, // FOCCFG Frequency Offset Compensation Configuration 
    0x6C, // BSCFG Bit Synchronization Configuration 
    0x43, // AGCCTRL2 AGC Control 
    0x40, // AGCCTRL1 AGC Control 
    0x91, // AGCCTRL0 AGC Control 
    0xE9 // FSCAL3 Frequency Synthesizer Calibration 
  },


  //**************************************************
  // Data rate 3
  //**************************************************
  // Deviation = 5.157471 
  // Base frequency = 868.299866 
  // Carrier frequency = 868.299866 
  // Channel number = 0 
  // Carrier frequency = 868.299866 
  // Modulated = true 
  // Modulation format = GFSK 
  // Manchester enable = false 
  // Sync word qualifier mode = 30/32 sync word bits detected 
  // Preamble count = 4 
  // Channel spacing = 199.951172 
  // Carrier frequency = 868.299866 
  // Data rate = 1.19948 
  // RX filter BW = 58.035714 
  // = Random TX mode 
  // Length config = Infinite packet length mode 
  // CRC enable = false 
  // Packet length = 255 
  // Device address = 0 
  // Address config = No address check 
  // = false 
  // PA ramping = false 
  // TX power = 0 
  {
    0x06, // FSCTRL1 Frequency Synthesizer Control 
    0xF5, // MDMCFG4 Modem configuration 
    0x83, // MDMCFG3 Modem Configuration 
    0x13, // MDMCFG2 10 Modem Configuration 
    0x15, // DEVIATN Modem Deviation Setting 
    0x56, // FREND1 Front End RX Configuration 
    0x16, // FOCCFG 17 Frequency Offset Compensation Configuration 
    0x6C, // BSCFG Bit Synchronization Configuration 
    0x03, // AGCCTRL2 AGC Control 
    0x40, // AGCCTRL1 AGC Control 
    0x91, // AGCCTRL0 AGC Control 
    0xE9 // FSCAL3 Frequency Synthesizer Calibration 
  },


  //**************************************************
  // Data rate 4
  //**************************************************
  // Deviation = 82.519531 
  // Base frequency = 868.299866 
  // Carrier frequency = 868.299866 
  // Channel number = 0 
  // Carrier frequency = 868.299866 
  // Modulated = true 
  // Modulation format = GFSK 
  // Manchester enable = false 
  // Sync word qualifier mode = 30/32 sync word bits detected 
  // Preamble count = 4 
  // Channel spacing = 199.951172 
  // Carrier frequency = 868.299866 
  // Data rate = 99.9756 
  // RX filter BW = 325.000000 
  // = Random TX mode 
  // Length config = Infinite packet length mode 
  // CRC enable = false 
  // Packet length = 255 
  // Device address = 0 
  // Address config = No address check 
  // = false 
  // PA ramping = false 
  // TX power = 0 
  {
    0x12, // FSCTRL1 Frequency Synthesizer Control 
    0x5B, // MDMCFG4 Modem configuration 
    0xF8, // MDMCFG3 Modem Configuration 
    0x13, // MDMCFG2 Modem Configuration 
    0x55, // DEVIATN Modem Deviation Setting 
    0xB6, // FREND1 Front End RX Configuration 
    0x1D, // FOCCFG Frequency Offset Compensation Configuration 
    0x1C, // BSCFG Bit Synchronization Configuration 
    0xC7, // AGCCTRL2 AGC Control 
    0x00, // AGCCTRL1 AGC Control 
    0xB0, // AGCCTRL0 AGC Control 
    0xEA // FSCAL3 Frequency Synthesizer Calibration 
  },


  //**************************************************
  // Data rate 5
  //**************************************************
  // Deviation = 126.953125 
  // Base frequency = 868.299866 
  // Carrier frequency = 868.299866 
  // Channel number = 0 
  // Carrier frequency = 868.299866 
  // Modulated = true 
  // Modulation format = GFSK 
  // Manchester enable = false 
  // Sync word qualifier mode = 30/32 sync word bits detected 
  // Preamble count = 4 
  // Channel spacing = 199.951172 
  // Carrier frequency = 868.299866 
  // Data rate = 49.9878 
  // RX filter BW = 541.666667 
  // = Random TX mode 
  // Length config = Infinite packet length mode 
  // CRC enable = false 
  // Packet length = 255 
  // Device address = 0 
  // Address config = No address check 
  // = false 
  // PA ramping = false 
  // TX power = 0 
  {
    0x12, // FSCTRL1 Frequency Synthesizer Control 
    0x2A, // MDMCFG4 Modem configuration 
    0xF8, // MDMCFG3 Modem Configuration 
    0x13, // MDMCFG2 Modem Configuration 
    0x62, // DEVIATN Modem Deviation Setting 
    0xB6, // FREND1 Front End RX Configuration 
    0x1D, // FOCCFG Frequency Offset Compensation Configuration 
    0x1C, // BSCFG Bit Synchronization Configuration 
    0xC7, // AGCCTRL2 AGC Control 
    0x00, // AGCCTRL1 AGC Control 
    0xB0, // AGCCTRL0 AGC Control 
    0xE9 // FSCAL3 Frequency Synthesizer Calibration 
  }
#endif

#if clkfreq == 24

  //**************************************************
  // Data rate 1 - CC1111
  //**************************************************
  // Deviation = 128.906250 
  // Base frequency = 868.299683 
  // Carrier frequency = 868.299683 
  // Channel number = 0 
  // Carrier frequency = 868.299683 
  // Modulated = true 
  // Modulation format = GFSK 
  // Manchester enable = false 
  // Sync word qualifier mode = No preamble/sync 
  // Preamble count = 4 
  // Channel spacing = 199.951172 
  // Carrier frequency = 868.299683 
  // Data rate = 249.756 
  // RX filter BW = 600.000000 
  // = Random TX mode 
  // Length config = Reserved 
  // CRC enable = false 
  // Packet length = 255 
  // Device address = 0 
  // Address config = No address check 
  // = false 
  // PA ramping = false 
  // TX power = 0 
  {
    0x0C, // FSCTRL1 Frequency Synthesizer Control 
    0x1D, // MDMCFG4 Modem configuration 
    0x55, // MDMCFG3 Modem Configuration 
    0x13, // MDMCFG2 Modem Configuration 
    0x63, // DEVIATN Modem Deviation Setting 
    0xB6, // FREND1 Front End RX Configuration 
    0x1D, // FOCCFG Frequency Offset Compensation Configuration 
    0x1C, // BSCFG Bit Synchronization Configuration 
    0xC7, // AGCCTRL2 AGC Control 
    0x00, // AGCCTRL1 AGC Control 
    0xB0, // AGCCTRL0 AGC Control 
    0xEA // FSCAL3 Frequency Synthesizer Calibration 
  },

  //**************************************************
  // Data rate 2 - CC1111
  //**************************************************
  // Deviation = 19.042969 
  // Base frequency = 868.299683 
  // Carrier frequency = 868.299683 
  // Channel number = 0 
  // Carrier frequency = 868.299683 
  // Modulated = true 
  // Modulation format = GFSK 
  // Manchester enable = false 
  // Sync word qualifier mode = 30/32 sync word bits detected 
  // Preamble count = 4 
  // Channel spacing = 199.951172 
  // Carrier frequency = 868.299683 
  // Data rate = 38.3606 
  // RX filter BW = 107.142857 
  // = Random TX mode 
  // Length config = Reserved 
  // CRC enable = false 
  // Packet length = 255 
  // Device address = 0 
  // Address config = No address check 
  // = false 
  // PA ramping = false 
  // TX power = 0 
  {
    0x06, // FSCTRL1 Frequency Synthesizer Control 
    0xBA, // MDMCFG4 Modem configuration 
    0xA3, // MDMCFG3 Modem Configuration 
    0x13, // MDMCFG2 Modem Configuration 
    0x35, // DEVIATN Modem Deviation Setting 
    0xB6, // FREND1 Front End RX Configuration 
    0x1D, // FOCCFG Frequency Offset Compensation Configuration 
    0x6C, // BSCFG Bit Synchronization Configuration 
    0x43, // AGCCTRL2 AGC Control 
    0x40, // AGCCTRL1 AGC Control 
    0x91, // AGCCTRL0 AGC Control 
    0xE9 // FSCAL3 Frequency Synthesizer Calibration 
  },

  //**************************************************
  // Data rate 3 - CC1111
  //**************************************************
  // Deviation = 5.126953 
  // Base frequency = 868.299683 
  // Carrier frequency = 868.299683 
  // Channel number = 0 
  // Carrier frequency = 868.299683 
  // Modulated = true 
  // Modulation format = GFSK 
  // Manchester enable = false 
  // Sync word qualifier mode = 30/32 sync word bits detected 
  // Preamble count = 4 
  // Channel spacing = 199.951172 
  // Carrier frequency = 868.299683 
  // Data rate = 1.19877 
  // RX filter BW = 62.500000 
  // = Random TX mode 
  // Length config = Reserved 
  // CRC enable = false 
  // Packet length = 255 
  // Device address = 0 
  // Address config = No address check 
  // = false 
  // PA ramping = false 
  // TX power = 0 
  {
    0x06, // FSCTRL1 Frequency Synthesizer Control 
    0xE5, // MDMCFG4 Modem configuration 
    0xA3, // MDMCFG3 Modem Configuration 
    0x13, // MDMCFG2 Modem Configuration 
    0x16, // DEVIATN Modem Deviation Setting 
    0xB6, // FREND1 Front End RX Configuration 
    0x1D, // FOCCFG Frequency Offset Compensation Configuration 
    0x6C, // BSCFG Bit Synchronization Configuration 
    0x43, // AGCCTRL2 AGC Control 
    0x40, // AGCCTRL1 AGC Control 
    0x91, // AGCCTRL0 AGC Control 
    0xE9 // FSCAL3 Frequency Synthesizer Calibration 
  },

  //**************************************************
  // Data rate 4 - CC1111
  //**************************************************
  // Deviation = 82.031250 
  // Base frequency = 868.299683 
  // Carrier frequency = 868.299683 
  // Channel number = 0 
  // Carrier frequency = 868.299683 
  // Modulated = true 
  // Modulation format = GFSK 
  // Manchester enable = false 
  // Sync word qualifier mode = 30/32 sync word bits detected 
  // Preamble count = 4 
  // Channel spacing = 199.951172 
  // Carrier frequency = 868.299683 
  // Data rate = 99.9756 
  // RX filter BW = 375.000000 
  // = Random TX mode 
  // Length config = Reserved 
  // CRC enable = false 
  // Packet length = 255 
  // Device address = 0 
  // Address config = No address check 
  // = false 
  // PA ramping = false 
  // TX power = 0 
  {
    0x06, // FSCTRL1 Frequency Synthesizer Control 
    0x4C, // MDMCFG4 Modem configuration 
    0x11, // MDMCFG3 Modem Configuration 
    0x13, // MDMCFG2 Modem Configuration 
    0x56, // DEVIATN Modem Deviation Setting 
    0xB6, // FREND1 Front End RX Configuration 
    0x1D, // FOCCFG Frequency Offset Compensation Configuration 
    0x6C, // BSCFG Bit Synchronization Configuration 
    0x43, // AGCCTRL2 AGC Control 
    0x40, // AGCCTRL1 AGC Control 
    0x91, // AGCCTRL0 AGC Control 
    0xEA // FSCAL3 Frequency Synthesizer Calibration 
  },

  //**************************************************
  // Data rate 5 - CC1111
  //**************************************************
  // Deviation = 128.906250 
  // Base frequency = 868.299683 
  // Carrier frequency = 868.299683 
  // Channel number = 0 
  // Carrier frequency = 868.299683 
  // Modulated = true 
  // Modulation format = GFSK 
  // Manchester enable = false 
  // Sync word qualifier mode = 30/32 sync word bits detected 
  // Preamble count = 4 
  // Channel spacing = 199.951172 
  // Carrier frequency = 868.299683 
  // Data rate = 49.9878 
  // RX filter BW = 600.000000 
  // = Random TX mode 
  // Length config = Reserved 
  // CRC enable = false 
  // Packet length = 255 
  // Device address = 0 
  // Address config = No address check 
  // = false 
  // PA ramping = false 
  // TX power = 0 
  {
    0x06, // FSCTRL1 Frequency Synthesizer Control 
    0x1B, // MDMCFG4 Modem configuration 
    0x11, // MDMCFG3 Modem Configuration 
    0x13, // MDMCFG2 Modem Configuration 
    0x63, // DEVIATN Modem Deviation Setting 
    0xB6, // FREND1 Front End RX Configuration 
    0x1D, // FOCCFG Frequency Offset Compensation Configuration 
    0x6C, // BSCFG Bit Synchronization Configuration 
    0x43, // AGCCTRL2 AGC Control 
    0x40, // AGCCTRL1 AGC Control 
    0x91, // AGCCTRL0 AGC Control 
    0xE9 // FSCAL3 Frequency Synthesizer Calibration 
  }
#endif
};

const uint8 __code pwrSetting[NUMBER_OF_FREQUENCIES_CC1110][9] = {
  //same for 1110 and 1111
  {0x03, 0x0D, 0x1D, 0x26, 0x57, 0x8E, 0x83, 0xC7, 0xC0}, //915MHz
  {0x03, 0x0D, 0x1D, 0x26, 0x57, 0x8E, 0x83, 0xC7, 0xC0}, //903MHz
  {0x03, 0x0E, 0x1E, 0x27, 0x8F, 0x50, 0x84, 0xCB, 0xC2}, //868MHz
  {0x12, 0x0E, 0x1D, 0x34, 0x2C, 0x60, 0x84, 0xC8, 0xC0}, //433.5MHz
  {0x03, 0x0E, 0x1E, 0x27, 0x8F, 0x50, 0x84, 0xCB, 0xC2}, //868.3MHz
  {0x12, 0x0D, 0x1C, 0x34, 0x2B, 0x51, 0x85, 0xCB, 0xC2} //315MHz
};

const uint8 __code frqSetting[NUMBER_OF_FREQUENCIES_CC1110][3] = {
#if clkfreq == 26
  {0x3B, 0x31, 0x23}, // 915 MHz
  {0x13, 0xBB, 0x22}, // 903 MHz
  {0x76, 0x62, 0x21}, // 868 MHz
  {0x4E, 0xAC, 0x10}, // 433.5 MHz
  {0x6A, 0x65, 0x21}, // 868.3 MHz
  {0x89, 0x1D, 0x0C} // 315 MHz
#endif
#if clkfreq == 24
  {0x00, 0x20, 0x26}, // 915 MHz
  {0x00, 0xA0, 0x25}, // 903 MHz
  {0xAA, 0x2A, 0x24}, // 868 MHz
  {0x00, 0x10, 0x12}, // 433.5 MHz
  {0xDD, 0x2D, 0x24}, // 868.3 MHz
  {0x00, 0x20, 0x0D} // 315 MHz
#endif
};


//code snippet

/* NOTE: The register settings are hard-coded for the predefined set of data
 * rates and frequencies. To enable other data rates or frequencies these
 * register settings should be adjusted accordingly (use SmartRF(R) Studio).
 */

RF_SETTINGS* rfset;
rfset = (RF_SETTINGS*)&rfSettings[dataRate-1];

RFST = STROBE_IDLE; // enter idle state

// Set transmit power (register setting is freq dependent)
// and configure the radio frequency to use
//FREQ0 = frqSetting[frequency-1][0];
//FREQ1 = frqSetting[frequency-1][1];
//FREQ2 = frqSetting[frequency-1][2];
FREQ0 = 0xDD;
FREQ1 = 0x2D;
FREQ2 = 0x24;
//PA_TABLE0 = pwrSetting[frequency-1][cfg.txPwr];
PA_TABLE0 = 0xC2;

//FSCTRL1 = rfset->fsctrl1; // Frequency synthesizer control.
//MDMCFG4 = rfset->mdmcfg4; // Modem configuration.
//MDMCFG3 = rfset->mdmcfg3; // Modem configuration.
//MDMCFG2 = rfset->mdmcfg2; // Modem configuration.
//DEVIATN = rfset->deviatn; // Modem deviation setting (when FSK modulation is enabled).
//FREND1 = rfset->frend1; // Front end RX configuration.
//FOCCFG = rfset->foccfg; // Frequency Offset Compensation Configuration.
//BSCFG = rfset->bscfg; // Bit synchronization Configuration.
//AGCCTRL2 = rfset->agcctrl2; // AGC control.
//AGCCTRL1 = rfset->agcctrl1; // AGC control.
//AGCCTRL0 = rfset->agcctrl1; // AGC control.
//FSCAL3 = rfset->fscal3; // Frequency synthesizer calibration.

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


// Common radio settings for CCxx1x, any frequency and data rate

FSCTRL0 = 0x00; // Frequency synthesizer control.
FREND0 = 0x10; // Front end RX configuration.
MCSM0 = 0x18; // Main Radio Control State Machine configuration.
// Freq. dependent value: 433 MHz band vs 868/915 MHz band:
//FSCAL2 = (frequency == FREQUENCY_4_CC1110) ? 0x0A : 0x2A;
FSCAL2 = 0x2A;
FSCAL1 = 0x00; // Frequency synthesizer calibration.
FSCAL0 = 0x1F; // Frequency synthesizer calibration.
TEST2 = 0x88; // Various test settings.
TEST1 = 0x31; // Various test settings.
TEST0 = 0x09; // Various test settings.
//perRssiOffset = 77;

//cfg.chanSpace = 0xC8;
//calcRate((uint32)cfg.chanSpace * 1000,18); // calulate the channel spacing (*1000 for Hz) according to data sheet equation

//MDMCFG1 = 0x20 | (B_E & 3); // Modem configuration. 4 preamble bytes and the exponent for channel spacing
MDMCFG1 = 0x22
//MDMCFG0 = B_M; // Modem configuration.
MDMCFG0 = 0xF8; // default setting???

//CHANNR = cfg.chanNumber; // Channel number.
CHANNR = 0x00;
//if (bProgMode) CHANNR += cfg.progChanOffset;
MCSM1 = 0x30; // Main Radio Control State Machine configuration.
// debug config IOCFG2 = 0x0B; // GDO2 output pin configuration.
// debug config IOCFG0 = 0x06; // GDO0 output pin configuration. Sync word.
PKTCTRL1 = 0x04; // Packet automation control.
PKTCTRL0 = 0x45; // Packet automation control. Data whitening on.
ADDR = 0x00; // Device address. Not used.
//PKTLEN = MAX_PACKET_LENGTH;
//if (cfg.doEncryption)
//  PKTLEN = cfg.pktLen16 + radioPktOverhead; // two networkID bytes and the data length byte
// else

// try 12 data bytes, 2 netID bytes & 1 data length byte
PKTLEN = 0x0F;

//PKTLEN = cfg.pktLen + radioPktOverhead;

//end of code snippet
