/**
  LCD Generated Driver File
  
  @Company
    Microchip Technology Inc.

  @File Name
    lcd.c

  @Summary
    This is the generated driver implementation file for the LCD driver using MPLAB(c) Code Configurator

  @Description
    This header file provides implementations for driver APIs for LCD.
    Generation Information :
        Product Revision  :  MPLAB(c) Code Configurator - 4.15
        Device            :  PIC16LF1937
        Driver Version    :  1.0
    The generated drivers are tested against the following:
        Compiler          :  XC8 1.35
        MPLAB             :  MPLAB X 3.40
*/

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
  Section: Included Files
*/

#include <xc.h>
#include "lcd.h"

/**
  Section: LCD APIs
*/

void LCD_Initialize(void)
{
    // Configure LCDPS; // Wave form type A or B; // Bias Mode
    // Prescaler - 1:16 - 1:1
    LCDPS = 0;
    WFT = 1;        // B type
    LCDPSbits.LP = 0;
    T1OSCEN = 1;    // activate the 32khz oscillator for our clock source

    /*******************************************************/
    /* User is responsible to enable the needed segments   */
    /* Replace the code in the next 3 lines for your glass */
    /*******************************************************/
    LCDSE0 = 0x37;
    LCDSE1 = 0x14;
    LCDSE2 = 0x13;

    /*******************************************************/
    // Configure LCDCON /LCD enbled /LCD enabled in sleep /LCD Clock Select - T1OSC
    // LCD Commons - 1/4
    LCDCON = 0;
    SLPEN = 0;
    WERR = 0;
    LCDCONbits.CS = 1;
    LCDCONbits.LMUX = 3;

    // clear ALL SEGMENT DATA
    LCDDATA0 = 0;
    LCDDATA1 = 0;
    LCDDATA2 = 0;
    LCDDATA3 = 0;
    LCDDATA4 = 0;
    LCDDATA5 = 0;
    LCDDATA6 = 0;
    LCDDATA7 = 0;
    LCDDATA8 = 0;
    LCDDATA9 = 0;
    LCDDATA10 = 0;
    LCDDATA11 = 0;

    LCDIF = 0;

    // Reference ladder control
    LCDRL = 0x30;

    // Configure LCDREF / Internal reference enabled /Internal Reference Source
    // Internal Reference always on
    LCDREF = 0;
    LCDIRE = 1;
    LCDIRS = 0;
    LCDIRI = 0;
    LCDCST = 0;     // maximum contrast
    LCD_Enable();
}

void LCD_Enable (void)
{
    LCDCONbits.LCDEN = 1;
}

void LCD_Disable (void)
{
    LCDCONbits.LCDEN = 0;    
}

void LCD_EnableSleepMode (void)
{
    LCDCONbits.SLPEN = 1;
}

void LCD_DisableSleepMode (void) 
{
    LCDCONbits.SLPEN = 0;    
}

void LCD_SetContrast (unsigned int value)
{
    LCDCSTbits.LCDCST = value;  
}

void LCD_SetIntervalAPowerMode (unsigned int value)
{
    LCDRLbits.LRLAP = value;      
}

void LCD_SetIntervalBPowerMode (unsigned int value)
{
    LCDRLbits.LRLBP = value;      
}

void LCD_SetPowerDistribution (unsigned int value)
{
    LCDRLbits.LRLAT = value;       
}

bool LCD_IsActive (void)
{
    return LCDPSbits.LCDA;
}

bool LCD_HasWriteFailureOccurred (void)
{
    return LCDCONbits.WERR;
}

bool LCD_IsWritingAllowed (void)
{
    return LCDPSbits.WA;    
}


void LCD_DisplayOn_S1Num() 
{
    S1AON; S1BON; S1CON; S1DON; S1EON; S1FON; S1GON; 
}

void LCD_DisplayOff_S1Num()
{
    S1AOFF; S1BOFF; S1COFF; S1DOFF; S1EOFF; S1FOFF; S1GOFF; 
}

void LCD_S1Num (unsigned char num) 
{
    switch (num)
    {
        case 0: S1AON;   S1BON;   S1CON;   S1DON;   S1EON;   S1FON;   S1GOFF;  break;
        case 1: S1AOFF;  S1BON;   S1CON;   S1DOFF;  S1EOFF;  S1FOFF;  S1GOFF;  break;
        case 2: S1AON;   S1BON;   S1COFF;  S1DON;   S1EON;   S1FOFF;  S1GON;   break;
        case 3: S1AON;   S1BON;   S1CON;   S1DON;   S1EOFF;  S1FOFF;  S1GON;   break;
        case 4: S1AOFF;  S1BON;   S1CON;   S1DOFF;  S1EOFF;  S1FON;   S1GON;   break;
        case 5: S1AON;   S1BOFF;  S1CON;   S1DON;   S1EOFF;  S1FON;   S1GON;   break;
        case 6: S1AON;   S1BOFF;  S1CON;   S1DON;   S1EON;   S1FON;   S1GON;   break;
        case 7: S1AON;   S1BON;   S1CON;   S1DOFF;  S1EOFF;  S1FOFF;  S1GOFF;  break;
        case 8: S1AON;   S1BON;   S1CON;   S1DON;   S1EON;   S1FON;   S1GON;   break;
        case 9: S1AON;   S1BON;   S1CON;   S1DON;   S1EOFF;  S1FON;   S1GON;   break;

        default: S1AOFF; S1BOFF; S1COFF; S1DOFF; S1EOFF; S1FOFF; S1GOFF;
    }    
}
void LCD_DisplayOn_S2Num() 
{
    S2AON; S2BON; S2CON; S2DON; S2EON; S2FON; S2GON; 
}

void LCD_DisplayOff_S2Num()
{
    S2AOFF; S2BOFF; S2COFF; S2DOFF; S2EOFF; S2FOFF; S2GOFF; 
}

void LCD_S2Num (unsigned char num) 
{
    switch (num)
    {
        case 0: S2AON;   S2BON;   S2CON;   S2DON;   S2EON;   S2FON;   S2GOFF;  break;
        case 1: S2AOFF;  S2BON;   S2CON;   S2DOFF;  S2EOFF;  S2FOFF;  S2GOFF;  break;
        case 2: S2AON;   S2BON;   S2COFF;  S2DON;   S2EON;   S2FOFF;  S2GON;   break;
        case 3: S2AON;   S2BON;   S2CON;   S2DON;   S2EOFF;  S2FOFF;  S2GON;   break;
        case 4: S2AOFF;  S2BON;   S2CON;   S2DOFF;  S2EOFF;  S2FON;   S2GON;   break;
        case 5: S2AON;   S2BOFF;  S2CON;   S2DON;   S2EOFF;  S2FON;   S2GON;   break;
        case 6: S2AON;   S2BOFF;  S2CON;   S2DON;   S2EON;   S2FON;   S2GON;   break;
        case 7: S2AON;   S2BON;   S2CON;   S2DOFF;  S2EOFF;  S2FOFF;  S2GOFF;  break;
        case 8: S2AON;   S2BON;   S2CON;   S2DON;   S2EON;   S2FON;   S2GON;   break;
        case 9: S2AON;   S2BON;   S2CON;   S2DON;   S2EOFF;  S2FON;   S2GON;   break;

        default: S2AOFF; S2BOFF; S2COFF; S2DOFF; S2EOFF; S2FOFF; S2GOFF;
    }    
}
void LCD_DisplayOn_S3Num() 
{
    S3AON; S3BON; S3CON; S3DON; S3EON; S3FON; S3GON; 
}

void LCD_DisplayOff_S3Num()
{
    S3AOFF; S3BOFF; S3COFF; S3DOFF; S3EOFF; S3FOFF; S3GOFF; 
}

void LCD_S3Num (unsigned char num) 
{
    switch (num)
    {
        case 0: S3AON;   S3BON;   S3CON;   S3DON;   S3EON;   S3FON;   S3GOFF;  break;
        case 1: S3AOFF;  S3BON;   S3CON;   S3DOFF;  S3EOFF;  S3FOFF;  S3GOFF;  break;
        case 2: S3AON;   S3BON;   S3COFF;  S3DON;   S3EON;   S3FOFF;  S3GON;   break;
        case 3: S3AON;   S3BON;   S3CON;   S3DON;   S3EOFF;  S3FOFF;  S3GON;   break;
        case 4: S3AOFF;  S3BON;   S3CON;   S3DOFF;  S3EOFF;  S3FON;   S3GON;   break;
        case 5: S3AON;   S3BOFF;  S3CON;   S3DON;   S3EOFF;  S3FON;   S3GON;   break;
        case 6: S3AON;   S3BOFF;  S3CON;   S3DON;   S3EON;   S3FON;   S3GON;   break;
        case 7: S3AON;   S3BON;   S3CON;   S3DOFF;  S3EOFF;  S3FOFF;  S3GOFF;  break;
        case 8: S3AON;   S3BON;   S3CON;   S3DON;   S3EON;   S3FON;   S3GON;   break;
        case 9: S3AON;   S3BON;   S3CON;   S3DON;   S3EOFF;  S3FON;   S3GON;   break;

        default: S3AOFF; S3BOFF; S3COFF; S3DOFF; S3EOFF; S3FOFF; S3GOFF;
    }    
}
// end of file
     
        

        
