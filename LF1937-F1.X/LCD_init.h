#include <time.h>//TODO might not be necessary
#include <stdint.h>
#include <stdbool.h>

#pragma config FOSC = INTOSC    // Oscillator Selection (INTOSC oscillator: I/O function on CLKIN pin)
#pragma config WDTE = OFF       // Watchdog Timer Enable (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable (PWRT disabled)
#pragma config MCLRE = ON       // MCLR Pin Function Select (MCLR/VPP pin function is MCLR)
#pragma config CP = OFF         // Flash Program Memory Code Protection (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Memory Code Protection (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable (Brown-out Reset disabled)
#pragma config CLKOUTEN = ON    // Clock Out Enable (CLKOUT function is enabled on the CLKOUT pin)
#pragma config IESO = OFF       // Internal/External Switchover (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable (Fail-Safe Clock Monitor is disabled)
#pragma config WRT = OFF        // Flash Memory Self-Write Protection (Write protection off)
#pragma config PLLEN = ON       // PLL Enable (4x PLL enabled)
#pragma config STVREN = ON      // Stack Overflow/Underflow Reset Enable (Stack Overflow or Underflow will cause a Reset)
#pragma config BORV = LO        // Brown-out Reset Voltage Selection (Brown-out Reset Voltage (Vbor), low trip point selected.)
#pragma config LVP = ON         // Low-Voltage Programming Enable (Low-voltage programming enabled)

#define _XTAL_FREQ  32000000 //TODO can probalby remove this stuff
#define ACQ_US_DELAY 5

/*
 AAAAAA
F      B
F      B
F      B
 GGGGGG
E      C
E      C
E      C
 DDDDDD  DP
*/
//seven seg init
#define SEG_A   0x01 //0000 0001
#define SEG_B   0x02 //0000 0010
#define SEG_C   0x04 //0000 0100
#define SEG_D   0x08 //0000 1000
#define SEG_E   0x10 //0001 0000
#define SEG_F   0x20 //0010 0000
#define SEG_G   0x40 //0100 0000
#define SEG_DP  0x80 //1000 0000 

#define DIGIT_0 (SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F)
#define DIGIT_1 (SEG_B | SEG_C)
#define DIGIT_2 (SEG_A | SEG_B | SEG_G | SEG_E | SEG_D)
#define DIGIT_3 (SEG_A | SEG_B | SEG_C | SEG_G | SEG_D)
#define DIGIT_4 (SEG_F | SEG_G | SEG_C | SEG_B)
#define DIGIT_5 (SEG_A | SEG_F | SEG_G | SEG_C | SEG_D)
#define DIGIT_6 (SEG_A | SEG_F | SEG_G | SEG_C | SEG_D | SEG_E)
#define DIGIT_7 (SEG_A | SEG_B | SEG_C)
#define DIGIT_8 (SEG_A | SEG_B | SEG_C | SEG_D | SEG_E | SEG_F | SEG_G)
#define DIGIT_9 (SEG_A | SEG_B | SEG_C | SEG_F | SEG_G)
#define DIGIT_A (SEG_A | SEG_B | SEG_C | SEG_E | SEG_F | SEG_G)
#define DIGIT_B (SEG_F | SEG_G | SEG_C | SEG_D | SEG_E)
#define DIGIT_C (SEG_A | SEG_F | SEG_E | SEG_D)
#define DIGIT_D (SEG_B | SEG_C | SEG_D | SEG_E | SEG_G)
#define DIGIT_E (SEG_A | SEG_F | SEG_G | SEG_E | SEG_D)
#define DIGIT_F (SEG_A | SEG_F | SEG_G | SEG_E)

// Glass pin 5
    #define RC      SEG0COM0
    #define BATT    SEG0COM1
    #define MINUS   SEG0COM2
    #define AC      SEG0COM3

// Glass pin 6
    #define DH  SEG1COM0
    #define RH  SEG1COM1
    #define BC4 SEG1COM2
    #define DP4 SEG1COM3

// Glass pin 7
    #define A3  SEG2COM0
    #define F3  SEG2COM1
    #define E3  SEG2COM2
    #define D3  SEG2COM3

// Glass pin 8
    #define B3  SEG4COM0
    #define G3  SEG4COM1
    #define C3  SEG4COM2
    #define DP3 SEG4COM3

// Glass pin 9
    #define A2  SEG5COM0
    #define F2  SEG5COM1
    #define E2  SEG5COM2
    #define D2  SEG5COM3

// Glass pin 10
    #define B2  SEG10COM0
    #define G2  SEG10COM1
    #define C2  SEG10COM2
    #define DP2 SEG10COM3

// Glass pin 11
    #define A1  SEG12COM0
    #define F1  SEG12COM1
    #define E1  SEG12COM2
    #define D1  SEG12COM3

// Glass pin 12
    #define B1  SEG16COM0
    #define G1  SEG16COM1
    #define C1  SEG16COM2

//#define    SEG16COM3
// Glass pin 13
    #define S1      SEG17COM0
    #define S2      SEG17COM1
    #define MILLI   SEG17COM2
    #define MEGA    SEG17COM3

// Glass pin 14
    #define AMPS    SEG20COM0
    #define VOLT    SEG20COM1
    #define KILO    SEG20COM2
    #define OHMS    SEG20COM3

typedef union{
    unsigned char   val;
    struct{
        unsigned    seg_dp : 1;
        unsigned    seg_g : 1;
        unsigned    seg_f : 1;
        unsigned    seg_e : 1;
        unsigned    seg_d : 1;
        unsigned    seg_c : 1;
        unsigned    seg_b : 1;
        unsigned    seg_a : 1;
    };
} SEVEN_SEGMENT_TYPE;

typedef union{
    uint16_t    val;
    struct{
        unsigned    digit0 : 4;
        unsigned    digit1 : 4;
        unsigned    digit2 : 4;
        unsigned    digit3 : 4;
    };
} BCD_TYPE;

const SEVEN_SEGMENT_TYPE   segment_data[] = {DIGIT_0, DIGIT_1, DIGIT_2,
         DIGIT_3, DIGIT_4, DIGIT_5, DIGIT_6, DIGIT_7, DIGIT_8, DIGIT_9, 
         DIGIT_A, DIGIT_B, DIGIT_C, DIGIT_D, DIGIT_E, DIGIT_F};