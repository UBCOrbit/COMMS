//USER GUIDE: http://www.ti.com/lit/ug/swru295e/swru295e.pdf
/*
//PIN CONFIG -
 MISO (10) PC2
 MOSI (11) PC3
 CS   (29) PB10
 SCL 
*/
//CC1120 STATUS BYTES
#define MIDLE 0b0001000
#define MRX 0b0011000
#define MTX 0b0101000
#define RXERR 0b1101000
#define TXERR 0b1111000
#define MCAL 0b100000

//STROBE COMMAND ADDRESSES AND FIFO ADDRESSES
#define SRES 0x30 //chip reset
#define SRX 0x34 //chip receive mode
#define STX 0x35 //chip transmit mode
#define SIDLE 0x36 //chip idle
#define SFRX 0x3A //chip rx fifo flush (when in error state)
#define SFTX 0x3B //chip tx fifo flush
#define SNOP 0x3D //chip do nothing (for status checking)
#define FIFOW 0b00111111 //address for tx fifo
#define FIFOR 0b10111111 //address for rx fifo

//EXTENDED REGISTERS
#define IF_MIX_CFG 0x00
#define FREQOFF_CFG 0x01
#define TOC_CFG 0x02
#define MARC_SPARE 0x03
#define ECG_CFG 0x04
#define CFM_DATA_CFG 0x05
#define EXT_CTRL 0x06
#define RCCAL_FINE 0x07
#define RCCAL_COARSE 0x08
#define RCCAL_OFFSET 0x09
#define FREQOFF1 0x0A
#define FREQOFF0 0x0B
#define FREQ2 0x0C //freq configuration register. refer to data sheet for formula to be used
#define FREQ1 0x0D 
#define FREQ0 0x0E 
#define IF_ADC2 0x0F
#define IF_ADC1 0x10
#define IF_ADC0 0x11
#define FS_DIG1 0x12
#define FS_DIG0 0x13
#define FS_CAL3 0x14
#define FS_CAL2 0x15
#define FS_CAL1 0x16
#define FS_CAL0 0x17
#define FS_CHP 0x18
#define FS_DIVTWO 0x19
#define FS_DSM1 0x1A
#define FS_DSM0 0x1B
#define FS_DVC1 0x1C
#define FS_DVC0 0x1D
#define FS_LBI 0x1E
#define FS_PFD 0x1F
#define FS_PRE 0x20
#define FS_REG_DIV_CML 0x21
#define FS_SPARE 0x22
#define FS_VCO4 0x23
#define FS_VCO3 0x24
#define FS_VCO2 0x25
#define FS_VCO1 0x26
#define FS_VCO0 0x27
#define GBIAS6 0x28
#define GBIAS5 0x29
#define GBIAS4 0x2A
#define GBIAS3 0x2B
#define GBIAS2 0x2C
#define GBIAS1 0x2D
#define GBIAS0 0x2E
#define IFAMP 0x2F
#define LNA 0x30
#define RXMIX 0x31
#define XOSC5 0x32
#define XOSC4 0x33
#define XOSC3 0x34
#define XOSC2 0x35
#define XOSC1 0x36
#define XOSC0 0x37
#define ANALOG_SPARE 0x38
#define PA_CFG3 0x39
#define WOR_TIME1 0x64
#define WOR_TIME0 0x65
#define WOR_CAPTURE1 0x66
#define WOR_CAPTURE0 0x67
#define BIST 0x68
#define DCFILTOFFSET_I1 0x69
#define DCFILTOFFSET_I0 0x6A
#define DCFILTOFFSET_Q1 0x6B
#define DCFILTOFFSET_Q0 0x6C
#define IQIE_I1 0x6D
#define IQIE_I0 0x6E
#define IQIE_Q1 0x6F
#define IQIE_Q0 0x70
#define RSSI1 0x71
#define RSSI0 0x72
#define MARCSTATE 0x73
#define LQI_VAL 0x74
#define PQT_SYNC_ERR 0x75
#define DEM_STATUS 0x76
#define FREQOFF_EST1 0x77
#define FREQOFF_EST0 0x78
#define AGC_GAIN3 0x79
#define AGC_GAIN2 0x7A
#define AGC_GAIN1 0x7B
#define AGC_GAIN0 0x7C
#define CFM_RX_DATA_OUT 0x7D
#define CFM_TX_DATA_IN 0x7E
#define ASK_SOFT_RX_DATA 0x7F
#define RNDGEN 0x80
#define MAGN2 0x81
#define MAGN1 0x82
#define MAGN0 0x83
#define ANG1 0x84
#define ANG0 0x85
#define CHFILT_I2 0x86
#define CHFILT_I1 0x87
#define CHFILT_I0 0x88
#define CHFILT_Q2 0x89
#define CHFILT_Q1 0x8A
#define CHFILT_Q0 0x8B
#define GPIO_STATUS 0x8C
#define FSCAL_CTRL 0x8D
#define PHASE_ADJUST 0x8E
#define PARTNUMBER 0x8F
#define PARTVERSION 0x90
#define SERIAL_STATUS 0x91
#define MODEM_STATUS1 0x92
#define MODEM_STATUS0 0x93
#define MARC_STATUS1 0x94
#define MARC_STATUS0 0x95
#define PA_IFAMP_TEST 0x96
#define FSRF_TEST 0x97
#define PRE_TEST 0x98
#define PRE_OVR 0x99
#define ADC_TEST 0x9A
#define DVC_TEST 0x9B
#define ATEST 0x9C
#define ATEST_LVDS 0x9D
#define ATEST_MODE 0x9E
#define XOSC_TEST1 0x9F
#define XOSC_TEST0 0xA0
#define RXFIRST 0xD2
#define TXFIRST 0xD3
#define RXLAST 0xD4
#define TXLAST 0xD5
#define NUM_TXBYTES 0xD6
#define NUM_RXBYTES 0xD7
#define FIFO_NUM_TXBYTES 0xD8
#define FIFO_NUM_RXBYTES 0xD9 

//REGULAR REGISTERS
#define IOCFG3 0x00 //gpio3 pin cfg; analog transfer, invert output, output selection (default pkt_sync_rtxtx)
#define IOCFG2 0x01 //gpio2 pin cfg; '' (default pkt_crc_ok)
#define IOCFG1 0x02 //gpio1 pin cfg; '' (default HIGHZ, acts as SO when CSn is low)
#define IOCFG0 0x03 //gpio0 pin cfgl '' (default EXT OSC EN)
#define SYNC3 0x04 //sync3-0 is sync word
#define SYNC2 0x05
#define SYNC1 0x06
#define SYNC0 0x07
#define SYNC_CFG1 0x08 //sync word detection settings; preamble quality check, sync word threshold
#define SYNC_CFG0 0x09 //sync word length settings; sync word mode, sync word bit check
#define DEVIATION_M 0x10 //frequency deviation
#define MODCFG_DEV_E 0x0B
#define DCFILT_CFG 0x0C
#define PREAMBLE_CFG1 0x0D //preamble settings; number of preamble bites, preamble byte cfg
#define PREAMBLE_CFG0 0x0E //preamble settings; preamble detection enable, pqt timeout, soft pqt
#define FREQ_IF_CFG 0x0F //Frequency synthesizer cfg
#define IQIC 0x10
#define CHAN_BW 0x11
#define MDMCFG1 0x12
#define MDMCFG0 0x13
#define SYMBOL_RATE2 0x14
#define SYMBOL_RATE1 0x15
#define SYMBOL_RATE0 0x16
#define AGC_REF 0x17
#define AGC_CS_THR 0x18
#define AGC_GAIN_ADJUST 0x19
#define AGC_CFG3 0x1A
#define AGC_CFG2 0x1B
#define AGC_CFG1 0x1C
#define AGC_CFG0 0x1D
#define FIFO_CFG 0x1E //tx and rx fifo sizes
#define DEV_ADDR 0x1F
#define SETTLING_CFG 0x20 //frequency settling cfg
#define FS_CFG 0x21 //
#define WOR_CFG1 0x22
#define WOR_CFG0 0x23
#define WOR_EVENT0_MSB 0x24
#define WOR_EVENT0_LSB 0x25
#define PKT_CFG2 0x26
#define PKT_CFG1 0x27
#define PKT_CFG0 0x28 //packet length cfg, packet bits, UART mode, UART swap
#define RFEND_CFG1 0x29 //mode which radio enters after receiving good packet, syncword timeout, rx timeout qualifier
#define RFEND_CFG0 0x2A
#define PA_CFG2 0x2B
#define PA_CFG1 0x2C
#define PA_CFG0 0x2D
#define PKT_LEN 0x2E //packet length if chosen to be fixed in PKT_CFG0 


//uint8_t bytei; //byte received from spi, mainly used for status check
//uint8_t datai; //byte received from spi, contains data from issued command, such as value in a register
typedef struct registerSetting_s registerSetting_t;

struct registerSetting_s{
  uint8_t addr;
  uint8_t data;
};


//==================================================

static const registerSetting_t standardRegisters[]={ //configure register settings here
  {IOCFG3,              0xB0}, //GPIO3 IO Pin Configuration
  {IOCFG2,              0x06}, //GPIO2 IO Pin Configuration
  {IOCFG1,              0xB0}, //GPIO1 IO Pin Configuration
  {IOCFG0,              0x40}, //GPIO0 IO Pin Configuration
  {SYNC3,               0x93}, //Sync Word Configuration [31:24]
  {SYNC2,               0x0B}, //Sync Word Configuration [23:16]
  {SYNC1,               0x51}, //Sync Word Configuration [15:8]
  {SYNC0,               0xDE}, //Sync Word Configuration [7:0]
  {SYNC_CFG1,           0x0B}, //Sync Word Detection Configuration Reg. 1
  {SYNC_CFG0,           0x17}, //Sync Word Length Configuration Reg. 0
  {DEVIATION_M,         0x06}, //Frequency Deviation Configuration
  {MODCFG_DEV_E,        0x03}, //Modulation Format and Frequency Deviation Configur..
  {DCFILT_CFG,          0x1C}, //Digital DC Removal Configuration
  {PREAMBLE_CFG1,       0x18}, //Preamble Length Configuration Reg. 1
  {PREAMBLE_CFG0,       0x2A}, //Preamble Detection Configuration Reg. 0
  {FREQ_IF_CFG,         0x40}, //RX Mixer Frequency Configuration
  {IQIC,                0xC6}, //Digital Image Channel Compensation Configuration
  {CHAN_BW,             0x08}, //Channel Filter Configuration
  {MDMCFG1,             0x46}, //General Modem Parameter Configuration Reg. 1
  {MDMCFG0,             0x05}, //General Modem Parameter Configuration Reg. 0
  {SYMBOL_RATE2,        0x43}, //Symbol Rate Configuration Exponent and Mantissa [1..
  {SYMBOL_RATE1,        0xA9}, //Symbol Rate Configuration Mantissa [15:8]
  {SYMBOL_RATE0,        0x2A}, //Symbol Rate Configuration Mantissa [7:0]
  {AGC_REF,             0x20}, //AGC Reference Level Configuration
  {AGC_CS_THR,          0x19}, //Carrier Sense Threshold Configuration
  {AGC_GAIN_ADJUST,     0x00}, //RSSI Offset Configuration
  {AGC_CFG3,            0x91}, //Automatic Gain Control Configuration Reg. 3
  {AGC_CFG2,            0x20}, //Automatic Gain Control Configuration Reg. 2
  {AGC_CFG1,            0xA9}, //Automatic Gain Control Configuration Reg. 1
  {AGC_CFG0,            0xCF}, //Automatic Gain Control Configuration Reg. 0
  {FIFO_CFG,            64}, //FIFO Configuration
  {DEV_ADDR,            0x00}, //Device Address Configuration
  {SETTLING_CFG,        0x03}, //Frequency Synthesizer Calibration and Settling Con..
  {FS_CFG,              0b00010100}, //Frequency Synthesizer Configuration
  {WOR_CFG1,            0x08}, //eWOR Configuration Reg. 1
  {WOR_CFG0,            0x21}, //eWOR Configuration Reg. 0
  {WOR_EVENT0_MSB,      0x00}, //Event 0 Configuration MSB
  {WOR_EVENT0_LSB,      0x00}, //Event 0 Configuration LSB
  {PKT_CFG2,            0x04}, //Packet Configuration Reg. 2
  {PKT_CFG1,            0x05}, //Packet Configuration Reg. 1
  {PKT_CFG0,            0x00}, //Packet Configuration Reg. 0
  {RFEND_CFG1,          0x0F}, //RFEND Configuration Reg. 1
  {RFEND_CFG0,          0x00}, //RFEND Configuration Reg. 0
  {PA_CFG2,             0x7F}, //Power Amplifier Configuration Reg. 2
  {PA_CFG1,             0x56}, //Power Amplifier Configuration Reg. 1
  {PA_CFG0,             0x7C}, //Power Amplifier Configuration Reg. 0
  {PKT_LEN,             127} //Packet Length Configuration
};

//==================================================

static const registerSetting_t extendedRegisters[]={ //configure extended register settings here
{IF_MIX_CFG,          0x00}, //IF Mix Configuration
  {FREQOFF_CFG,         0x22}, //Frequency Offset Correction Configuration
  {TOC_CFG,             0x0B}, //Timing Offset Correction Configuration
  {MARC_SPARE,          0x00}, //MARC Spare
  {ECG_CFG,             0x00}, //External Clock Frequency Configuration
  {CFM_DATA_CFG,        0x00}, //Custom frequency modulation enable
  {EXT_CTRL,            0x01}, //External Control Configuration
  {RCCAL_FINE,          0x00}, //RC Oscillator Calibration Fine
  {RCCAL_COARSE,        0x00}, //RC Oscillator Calibration Coarse
  {RCCAL_OFFSET,        0x00}, //RC Oscillator Calibration Clock Offset
  {FREQOFF1,            0x00}, //Frequency Offset MSB
  {FREQOFF0,            0x00}, //Frequency Offset LSB
  {FREQ2,               0x6C}, //Frequency Configuration [23:16]
  {FREQ1,               0x40}, //Frequency Configuration [15:8]
  {FREQ0,               0x00}, //Frequency Configuration [7:0]
  {IF_ADC2,             0x02}, //Analog to Digital Converter Configuration Reg. 2
  {IF_ADC1,             0xA6}, //Analog to Digital Converter Configuration Reg. 1
  {IF_ADC0,             0x04}, //Analog to Digital Converter Configuration Reg. 0
  {FS_DIG1,             0x00}, //Frequency Synthesizer Digital Reg. 1
  {FS_DIG0,             0x5F}, //Frequency Synthesizer Digital Reg. 0
  {FS_CAL3,             0x00}, //Frequency Synthesizer Calibration Reg. 3
  {FS_CAL2,             0x20}, //Frequency Synthesizer Calibration Reg. 2
  {FS_CAL1,             0x40}, //Frequency Synthesizer Calibration Reg. 1
  {FS_CAL0,             0x0E}, //Frequency Synthesizer Calibration Reg. 0
  {FS_CHP,              0x27}, //Frequency Synthesizer Charge Pump Configuration
  {FS_DIVTWO,           0x03}, //Frequency Synthesizer Divide by 2
  {FS_DSM1,             0x00}, //FS Digital Synthesizer Module Configuration Reg. 1
  {FS_DSM0,             0x33}, //FS Digital Synthesizer Module Configuration Reg. 0
  {FS_DVC1,             0xFF}, //Frequency Synthesizer Divider Chain Configuration ..
  {FS_DVC0,             0x17}, //Frequency Synthesizer Divider Chain Configuration ..
  {FS_LBI,              0x00}, //Frequency Synthesizer Local Bias Configuration
  {FS_PFD,              0x50}, //Frequency Synthesizer Phase Frequency Detector Con..
  {FS_PRE,              0x6E}, //Frequency Synthesizer Prescaler Configuration
  {FS_REG_DIV_CML,      0x14}, //Frequency Synthesizer Divider Regulator Configurat..
  {FS_SPARE,            0xAC}, //Frequency Synthesizer Spare
  {FS_VCO4,             0x13}, //FS Voltage Controlled Oscillator Configuration Reg..
  {FS_VCO3,             0x00}, //FS Voltage Controlled Oscillator Configuration Reg..
  {FS_VCO2,             0x4C}, //FS Voltage Controlled Oscillator Configuration Reg..
  {FS_VCO1,             0x9C}, //FS Voltage Controlled Oscillator Configuration Reg..
  {FS_VCO0,             0xB4}, //FS Voltage Controlled Oscillator Configuration Reg..
  {GBIAS6,              0x00}, //Global Bias Configuration Reg. 6
  {GBIAS5,              0x02}, //Global Bias Configuration Reg. 5
  {GBIAS4,              0x00}, //Global Bias Configuration Reg. 4
  {GBIAS3,              0x00}, //Global Bias Configuration Reg. 3
  {GBIAS2,              0x10}, //Global Bias Configuration Reg. 2
  {GBIAS1,              0x00}, //Global Bias Configuration Reg. 1
  {GBIAS0,              0x00}, //Global Bias Configuration Reg. 0
  {IFAMP,               0x01}, //Intermediate Frequency Amplifier Configuration
  {LNA,                 0x01}, //Low Noise Amplifier Configuration
  {RXMIX,               0x01}, //RX Mixer Configuration
  {XOSC5,               0x0E}, //Crystal Oscillator Configuration Reg. 5
  {XOSC4,               0xA0}, //Crystal Oscillator Configuration Reg. 4
  {XOSC3,               0x03}, //Crystal Oscillator Configuration Reg. 3
  {XOSC2,               0x04}, //Crystal Oscillator Configuration Reg. 2
  {XOSC1,               0x03}, //Crystal Oscillator Configuration Reg. 1
  {XOSC0,               0x00}, //Crystal Oscillator Configuration Reg. 0
  {ANALOG_SPARE,        0x00}, //Analog Spare
  {PA_CFG3,             0x00}, //Power Amplifier Configuration Reg. 3
  {WOR_TIME1,           0x00}, //eWOR Timer Counter Value MSB
  {WOR_TIME0,           0x00}, //eWOR Timer Counter Value LSB
  {WOR_CAPTURE1,        0x00}, //eWOR Timer Capture Value MSB
  {WOR_CAPTURE0,        0x00}, //eWOR Timer Capture Value LSB
  {BIST,                0x00}, //MARC Built-In Self-Test
  {DCFILTOFFSET_I1,     0xFC}, //DC Filter Offset I MSB
  {DCFILTOFFSET_I0,     0x66}, //DC Filter Offset I LSB
  {DCFILTOFFSET_Q1,     0x06}, //DC Filter Offset Q MSB
  {DCFILTOFFSET_Q0,     0xE6}, //DC Filter Offset Q LSB
  {IQIE_I1,             0xFD}, //IQ Imbalance Value I MSB
  {IQIE_I0,             0x15}, //IQ Imbalance Value I LSB
  {IQIE_Q1,             0x02}, //IQ Imbalance Value Q MSB
  {IQIE_Q0,             0xEF}, //IQ Imbalance Value Q LSB
  {RSSI1,               0xED}, //Received Signal Strength Indicator Reg. 1
  {RSSI0,               0x03}, //Received Signal Strength Indicator Reg.0
  {MARCSTATE,           0x33}, //MARC State
  {LQI_VAL,             0x80}, //Link Quality Indicator Value
  {PQT_SYNC_ERR,        0x9F}, //Preamble and Sync Word Error
  {DEM_STATUS,          0x01}, //Demodulator Status
  {FREQOFF_EST1,        0x00}, //Frequency Offset Estimate MSB
  {FREQOFF_EST0,        0x0E}, //Frequency Offset Estimate LSB
  {AGC_GAIN3,           0x27}, //Automatic Gain Control Reg. 3
  {AGC_GAIN2,           0xD1}, //Automatic Gain Control Reg. 2
  {AGC_GAIN1,           0x00}, //Automatic Gain Control Reg. 1
  {AGC_GAIN0,           0x3F}, //Automatic Gain Control Reg. 0
  {CFM_RX_DATA_OUT,     0x00}, //Custom Frequency Modulation RX Data
  {CFM_TX_DATA_IN,      0x00}, //Custom Frequency Modulation TX Data
  {ASK_SOFT_RX_DATA,    0x30}, //ASK Soft Decision Output
  {RNDGEN,              0x7F}, //Random Number Generator Value
  {MAGN2,               0x00}, //Signal Magnitude after CORDIC [16]
  {MAGN1,               0x00}, //Signal Magnitude after CORDIC [15:8]
  {MAGN0,               0x10}, //Signal Magnitude after CORDIC [7:0]
  {ANG1,                0x00}, //Signal Angular after CORDIC [9:8]
  {ANG0,                0xD5}, //Signal Angular after CORDIC [7:0]
  {CHFILT_I2,           0x0F}, //Channel Filter Data Real Part [18:16]
  {CHFILT_I1,           0xFF}, //Channel Filter Data Real Part [15:8]
  {CHFILT_I0,           0xEE}, //Channel Filter Data Real Part [7:0]
  {CHFILT_Q2,           0x00}, //Channel Filter Data Imaginary Part [18:16]
  {CHFILT_Q1,           0x00}, //Channel Filter Data Imaginary Part [15:8]
  {CHFILT_Q0,           0x11}, //Channel Filter Data Imaginary Part [7:0]
  {GPIO_STATUS,         0x00}, //General Purpose Input/Output Status
  {FSCAL_CTRL,          0x09}, //Frequency Synthesizer Calibration Control
  {PHASE_ADJUST,        0x00}, //Frequency Synthesizer Phase Adjust
  {PARTNUMBER,          0x48}, //Part Number
  {PARTVERSION,         0x21}, //Part Revision
  {SERIAL_STATUS,       0x00}, //Serial Status
  {MODEM_STATUS1,       0x11}, //Modem Status Reg. 1
  {MODEM_STATUS0,       0x00}, //Modem Status Reg. 0
  {MARC_STATUS1,        0x40}, //MARC Status Reg. 1
  {MARC_STATUS0,        0x00}, //MARC Status Reg. 0
  {PA_IFAMP_TEST,       0x00}, //Power Amplifier Intermediate Frequency Amplifier T..
  {FSRF_TEST,           0x00}, //Frequency Synthesizer Test
  {PRE_TEST,            0x00}, //Frequency Synthesizer Prescaler Test
  {PRE_OVR,             0x00}, //Frequency Synthesizer Prescaler Override
  {ADC_TEST,            0x00}, //Analog to Digital Converter Test
  {DVC_TEST,            0x0B}, //Digital Divider Chain Test
  {ATEST,               0x40}, //Analog Test
  {ATEST_LVDS,          0x00}, //Analog Test LVDS
  {ATEST_MODE,          0x00}, //Analog Test Mode
  {XOSC_TEST1,          0x3C}, //Crystal Oscillator Test Reg. 1
  {XOSC_TEST0,          0x00}, //Crystal Oscillator Test Reg. 0
  {RXFIRST,             0x00}, //RX FIFO Pointer First Entry
  {TXFIRST,             0x0A}, //TX FIFO Pointer First Entry
  {RXLAST,              0x00}, //RX FIFO Pointer Last Entry
  {TXLAST,              0x0E}, //TX FIFO Pointer Last Entry
  {NUM_TXBYTES,         0x04}, //TX FIFO Status
  {NUM_RXBYTES,         0x00}, //RX FIFO Status
  {FIFO_NUM_TXBYTES,    0x0F}, //TX FIFO Status
  {FIFO_NUM_RXBYTES,    0x00}, //RX FIFO Status
};

//==================================================
