/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using MPLAB(c) Code Configurator

  @Description:
    This header file provides implementations for pin APIs for all pins selected in the GUI.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.15
        Device            :  PIC16LF1937
        Version           :  1.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40

    Copyright (c) 2013 - 2015 released Microchip Technology Inc.  All rights reserved.

    Microchip licenses to you the right to use, modify, copy and distribute
    Software only when embedded on a Microchip microcontroller or digital signal
    controller that is integrated into your product or third party product
    (pursuant to the sublicense terms in the accompanying license agreement).

    You should refer to the license agreement accompanying this Software for
    additional information regarding your rights and obligations.

    SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
    EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
    MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
    IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
    CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
    OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
    INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
    CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
    SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
    (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.

*/


#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RA0 procedures
#define RA0_SetHigh()    do { LATAbits.LATA0 = 1; } while(0)
#define RA0_SetLow()   do { LATAbits.LATA0 = 0; } while(0)
#define RA0_Toggle()   do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define RA0_GetValue()         PORTAbits.RA0
#define RA0_SetDigitalInput()   do { TRISAbits.TRISA0 = 1; } while(0)
#define RA0_SetDigitalOutput()  do { TRISAbits.TRISA0 = 0; } while(0)
#define RA0_SetAnalogMode() do { ANSELAbits.ANSA0 = 1; } while(0)
#define RA0_SetDigitalMode()do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set RA2 procedures
#define RA2_SetHigh()    do { LATAbits.LATA2 = 1; } while(0)
#define RA2_SetLow()   do { LATAbits.LATA2 = 0; } while(0)
#define RA2_Toggle()   do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define RA2_GetValue()         PORTAbits.RA2
#define RA2_SetDigitalInput()   do { TRISAbits.TRISA2 = 1; } while(0)
#define RA2_SetDigitalOutput()  do { TRISAbits.TRISA2 = 0; } while(0)
#define RA2_SetAnalogMode() do { ANSELAbits.ANSA2 = 1; } while(0)
#define RA2_SetDigitalMode()do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set RA4 procedures
#define RA4_SetHigh()    do { LATAbits.LATA4 = 1; } while(0)
#define RA4_SetLow()   do { LATAbits.LATA4 = 0; } while(0)
#define RA4_Toggle()   do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define RA4_GetValue()         PORTAbits.RA4
#define RA4_SetDigitalInput()   do { TRISAbits.TRISA4 = 1; } while(0)
#define RA4_SetDigitalOutput()  do { TRISAbits.TRISA4 = 0; } while(0)
#define RA4_SetAnalogMode() do { ANSELAbits.ANSA4 = 1; } while(0)
#define RA4_SetDigitalMode()do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set RA5 procedures
#define RA5_SetHigh()    do { LATAbits.LATA5 = 1; } while(0)
#define RA5_SetLow()   do { LATAbits.LATA5 = 0; } while(0)
#define RA5_Toggle()   do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define RA5_GetValue()         PORTAbits.RA5
#define RA5_SetDigitalInput()   do { TRISAbits.TRISA5 = 1; } while(0)
#define RA5_SetDigitalOutput()  do { TRISAbits.TRISA5 = 0; } while(0)
#define RA5_SetAnalogMode() do { ANSELAbits.ANSA5 = 1; } while(0)
#define RA5_SetDigitalMode()do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set RA6 procedures
#define RA6_SetHigh()    do { LATAbits.LATA6 = 1; } while(0)
#define RA6_SetLow()   do { LATAbits.LATA6 = 0; } while(0)
#define RA6_Toggle()   do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define RA6_GetValue()         PORTAbits.RA6
#define RA6_SetDigitalInput()   do { TRISAbits.TRISA6 = 1; } while(0)
#define RA6_SetDigitalOutput()  do { TRISAbits.TRISA6 = 0; } while(0)

// get/set RA7 procedures
#define RA7_SetHigh()    do { LATAbits.LATA7 = 1; } while(0)
#define RA7_SetLow()   do { LATAbits.LATA7 = 0; } while(0)
#define RA7_Toggle()   do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define RA7_GetValue()         PORTAbits.RA7
#define RA7_SetDigitalInput()   do { TRISAbits.TRISA7 = 1; } while(0)
#define RA7_SetDigitalOutput()  do { TRISAbits.TRISA7 = 0; } while(0)

// get/set RB0 procedures
#define RB0_SetHigh()    do { LATBbits.LATB0 = 1; } while(0)
#define RB0_SetLow()   do { LATBbits.LATB0 = 0; } while(0)
#define RB0_Toggle()   do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define RB0_GetValue()         PORTBbits.RB0
#define RB0_SetDigitalInput()   do { TRISBbits.TRISB0 = 1; } while(0)
#define RB0_SetDigitalOutput()  do { TRISBbits.TRISB0 = 0; } while(0)
#define RB0_SetPullup()     do { WPUBbits.WPUB0 = 1; } while(0)
#define RB0_ResetPullup()   do { WPUBbits.WPUB0 = 0; } while(0)
#define RB0_SetAnalogMode() do { ANSELBbits.ANSB0 = 1; } while(0)
#define RB0_SetDigitalMode()do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set RB4 procedures
#define RB4_SetHigh()    do { LATBbits.LATB4 = 1; } while(0)
#define RB4_SetLow()   do { LATBbits.LATB4 = 0; } while(0)
#define RB4_Toggle()   do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define RB4_GetValue()         PORTBbits.RB4
#define RB4_SetDigitalInput()   do { TRISBbits.TRISB4 = 1; } while(0)
#define RB4_SetDigitalOutput()  do { TRISBbits.TRISB4 = 0; } while(0)
#define RB4_SetPullup()     do { WPUBbits.WPUB4 = 1; } while(0)
#define RB4_ResetPullup()   do { WPUBbits.WPUB4 = 0; } while(0)
#define RB4_SetAnalogMode() do { ANSELBbits.ANSB4 = 1; } while(0)
#define RB4_SetDigitalMode()do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set RB5 procedures
#define RB5_SetHigh()    do { LATBbits.LATB5 = 1; } while(0)
#define RB5_SetLow()   do { LATBbits.LATB5 = 0; } while(0)
#define RB5_Toggle()   do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define RB5_GetValue()         PORTBbits.RB5
#define RB5_SetDigitalInput()   do { TRISBbits.TRISB5 = 1; } while(0)
#define RB5_SetDigitalOutput()  do { TRISBbits.TRISB5 = 0; } while(0)
#define RB5_SetPullup()     do { WPUBbits.WPUB5 = 1; } while(0)
#define RB5_ResetPullup()   do { WPUBbits.WPUB5 = 0; } while(0)
#define RB5_SetAnalogMode() do { ANSELBbits.ANSB5 = 1; } while(0)
#define RB5_SetDigitalMode()do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set RC5 procedures
#define RC5_SetHigh()    do { LATCbits.LATC5 = 1; } while(0)
#define RC5_SetLow()   do { LATCbits.LATC5 = 0; } while(0)
#define RC5_Toggle()   do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define RC5_GetValue()         PORTCbits.RC5
#define RC5_SetDigitalInput()   do { TRISCbits.TRISC5 = 1; } while(0)
#define RC5_SetDigitalOutput()  do { TRISCbits.TRISC5 = 0; } while(0)

// get/set RD0 procedures
#define RD0_SetHigh()    do { LATDbits.LATD0 = 1; } while(0)
#define RD0_SetLow()   do { LATDbits.LATD0 = 0; } while(0)
#define RD0_Toggle()   do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define RD0_GetValue()         PORTDbits.RD0
#define RD0_SetDigitalInput()   do { TRISDbits.TRISD0 = 1; } while(0)
#define RD0_SetDigitalOutput()  do { TRISDbits.TRISD0 = 0; } while(0)
#define RD0_SetAnalogMode() do { ANSELDbits.ANSD0 = 1; } while(0)
#define RD0_SetDigitalMode()do { ANSELDbits.ANSD0 = 0; } while(0)

// get/set IO_RD1 aliases
#define IO_RD1_TRIS               TRISDbits.TRISD1
#define IO_RD1_LAT                LATDbits.LATD1
#define IO_RD1_PORT               PORTDbits.RD1
#define IO_RD1_ANS                ANSELDbits.ANSD1
#define IO_RD1_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define IO_RD1_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define IO_RD1_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define IO_RD1_GetValue()           PORTDbits.RD1
#define IO_RD1_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define IO_RD1_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define IO_RD1_SetAnalogMode()  do { ANSELDbits.ANSD1 = 1; } while(0)
#define IO_RD1_SetDigitalMode() do { ANSELDbits.ANSD1 = 0; } while(0)

// get/set RD3 procedures
#define RD3_SetHigh()    do { LATDbits.LATD3 = 1; } while(0)
#define RD3_SetLow()   do { LATDbits.LATD3 = 0; } while(0)
#define RD3_Toggle()   do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define RD3_GetValue()         PORTDbits.RD3
#define RD3_SetDigitalInput()   do { TRISDbits.TRISD3 = 1; } while(0)
#define RD3_SetDigitalOutput()  do { TRISDbits.TRISD3 = 0; } while(0)
#define RD3_SetAnalogMode() do { ANSELDbits.ANSD3 = 1; } while(0)
#define RD3_SetDigitalMode()do { ANSELDbits.ANSD3 = 0; } while(0)

// get/set RD4 procedures
#define RD4_SetHigh()    do { LATDbits.LATD4 = 1; } while(0)
#define RD4_SetLow()   do { LATDbits.LATD4 = 0; } while(0)
#define RD4_Toggle()   do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define RD4_GetValue()         PORTDbits.RD4
#define RD4_SetDigitalInput()   do { TRISDbits.TRISD4 = 1; } while(0)
#define RD4_SetDigitalOutput()  do { TRISDbits.TRISD4 = 0; } while(0)
#define RD4_SetAnalogMode() do { ANSELDbits.ANSD4 = 1; } while(0)
#define RD4_SetDigitalMode()do { ANSELDbits.ANSD4 = 0; } while(0)

// get/set RD7 procedures
#define RD7_SetHigh()    do { LATDbits.LATD7 = 1; } while(0)
#define RD7_SetLow()   do { LATDbits.LATD7 = 0; } while(0)
#define RD7_Toggle()   do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define RD7_GetValue()         PORTDbits.RD7
#define RD7_SetDigitalInput()   do { TRISDbits.TRISD7 = 1; } while(0)
#define RD7_SetDigitalOutput()  do { TRISDbits.TRISD7 = 0; } while(0)
#define RD7_SetAnalogMode() do { ANSELDbits.ANSD7 = 1; } while(0)
#define RD7_SetDigitalMode()do { ANSELDbits.ANSD7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/