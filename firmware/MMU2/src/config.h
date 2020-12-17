// main configuration file
#ifndef CONFIG_H_
#define CONFIG_H_

//UART1
#define UART1_BDR 115200

//communication uart0/1
#define UART_COM 1

#define DEFAULT_MODE  STEALTH_MODE
//#define DEFAULT_MODE  NORMAL_MODE


//#define CHOPPER_TIMING  CHOPPER_DEFAULT_12V
#define CHOPPER_TIMING  CHOPPER_DEFAULT_24V


// Print simple drive status information
//#define TMC_DEBUG

#define HOLD_MULTIPLIER    0.5  // Scales down the holding current from run current
#define INTERPOLATE       true  // Interpolate X/Y/Z_MICROSTEPS to 256

/* Stepper Drivers
*  Options: spi:TMC2130
*           uart:TMC2209,TMC2208(TMC2208 no stallguard)
*/
#define TMC2209            1

// SG_THR stallguard treshold (sensitivity),  TMC2209: 0...255. TMC2130: 63...-64
// !!! This setting is not universal, and the values set by different machines are different !!!
//12V
// #define TMC_SG_THR_SEL     50  //TMC2209 set to about 50, TMC2130 Set to about 31
// #define TMC_SG_THR_IDL     25  //TMC2209 set to about 20, TMC2130 Set to about 19
//24V
#define TMC_SG_THR_SEL     50  //TMC2209 set to about 50, TMC2130 Set to about 31
#define TMC_SG_THR_IDL     20  //TMC2209 set to about 20, TMC2130 Set to about 19

#define TMC_TCOOLTHRS      450     // TCOOLTHRS default

// TCOOLTHRS coolstep treshold, usable range 0-300
#define TMC_TCOOLTHRS_0    128  // ~2s until driver lowers to hold current
#define TMC_TCOOLTHRS_1    128
#define TMC_TCOOLTHRS_2    128

/* TMC drive set the motor current, the higher the current the greater the heat generation, 
*  the lower the current the smaller the torque, choose a balance point.
*
*  Set currents   0~31    {AX_PUL , AX_SEL , AX_IDL}
*/
// vsense = 1
// Rsense = 0.11
// MA = (CS+1)/32.0 * 0.180 /(Rsense+0.02) / 1.41421 * 1000;
// CS = 32.0*1.41421*mA/1000.0*(Rsense+0.02)/0.180 - 1;
// CS   ma
// 1	61,19208713
// 2	91,78813069
// 3	122,3841743
// 4	152,9802178
// 5	183,5762614
// 6	214,172305
// 7	244,7683485
// 8	275,3643921
// 9	305,9604356
// 10	336,5564792
// 11	367,1525228
// 12	397,7485663
// 13	428,3446099
// 14	458,9406535
// 15	489,536697
// 16	520,1327406
// 17	550,7287842
// 18	581,3248277
// 19	611,9208713
// 20	642,5169149
// 21	673,1129584
// 22	703,709002
// 23	734,3050455
// 24	764,9010891
// 25	795,4971327
// 26	826,0931762
// 27	856,6892198
// 28	887,2852634
// 29	917,8813069
// 30	948,4773505
// 31	979,0733941
// {AX_PUL , AX_SEL , AX_IDL}
#define CURRENT_HOLDING_STEALTH {8, 8, 8}
#define CURRENT_HOLDING_NORMAL  {8, 8, 8}
#define CURRENT_RUNNING_STEALTH {20, 22, 22}
#define CURRENT_RUNNING_NORMAL  {22, 23, 25}
#define CURRENT_HOMING          {8, 22, 22}

//number of extruders [1 2 3 4 5]
#define EXTRUDERS 7

#endif //CONFIG_H_
