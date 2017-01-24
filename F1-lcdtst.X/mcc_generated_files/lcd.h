/**
  LCD Generated Driver API Header File

  @Company
    Microchip Technology Inc.

  @File Name
    lcd.h

  @Summary
    This is the generated header file for the LCD driver using MPLAB(c) Code Configurator

  @Description
    This header file provides APIs for driver for LCD.
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

#ifndef _LCD_H
#define _LCD_H

/**
  Section: Included Files
*/

#include <xc.h>
#include <stdbool.h>
    
/**
    Section: Defines
*/ 
   
/**
    Defines: the segments pins
*/
#define SEG03      LCDSE0bits.SE3
#define SEG02      LCDSE0bits.SE2
#define SEG05      LCDSE0bits.SE5
#define SEG04      LCDSE0bits.SE4
#define SEG07      LCDSE0bits.SE7
#define SEG06      LCDSE0bits.SE6
#define SEG01      LCDSE0bits.SE1
#define SEG00      LCDSE0bits.SE0
#define SEG15      LCDSE1bits.SE15
#define SEG13      LCDSE1bits.SE13
#define SEG14      LCDSE1bits.SE14
#define SEG11      LCDSE1bits.SE11
#define SEG12      LCDSE1bits.SE12
#define SEG09      LCDSE1bits.SE9
#define SEG08      LCDSE1bits.SE8
#define SEG10      LCDSE1bits.SE10
#define SEG16      LCDSE2bits.SE16
#define SEG22      LCDSE2bits.SE22
#define SEG23      LCDSE2bits.SE23
#define SEG20      LCDSE2bits.SE20
#define SEG21      LCDSE2bits.SE21
#define SEG19      LCDSE2bits.SE19
#define SEG17      LCDSE2bits.SE17
#define SEG18      LCDSE2bits.SE18

#define S1A      LCDDATA1bits.SEG12COM0
#define S1B      LCDDATA2bits.SEG16COM0
#define S1C      LCDDATA8bits.SEG16COM2
#define S1D      LCDDATA10bits.SEG12COM3
#define S1E      LCDDATA7bits.SEG12COM2
#define S1F      LCDDATA4bits.SEG12COM1
#define S1G      LCDDATA5bits.SEG16COM1
#define S2A      LCDDATA0bits.SEG5COM0
#define S2B      LCDDATA1bits.SEG10COM0
#define S2C      LCDDATA7bits.SEG10COM2
#define S2D      LCDDATA9bits.SEG5COM3
#define S2E      LCDDATA6bits.SEG5COM2
#define S2F      LCDDATA3bits.SEG5COM1
#define S2G      LCDDATA4bits.SEG10COM1
#define S3A      LCDDATA0bits.SEG2COM0
#define S3B      LCDDATA0bits.SEG4COM0
#define S3C      LCDDATA6bits.SEG4COM2
#define S3D      LCDDATA9bits.SEG2COM3
#define S3E      LCDDATA6bits.SEG2COM2
#define S3F      LCDDATA3bits.SEG2COM1
#define S3G      LCDDATA3bits.SEG4COM1
#define RC       LCDDATA0bits.SEG0COM0
#define BATT     LCDDATA3bits.SEG0COM1
#define MINUS    LCDDATA6bits.SEG0COM2
#define AC       LCDDATA9bits.SEG0COM3
#define DH       LCDDATA0bits.SEG1COM0
#define RH       LCDDATA3bits.SEG1COM1
#define BC4      LCDDATA6bits.SEG1COM2
#define DP4      LCDDATA9bits.SEG1COM3
#define DP3      LCDDATA9bits.SEG4COM3
#define DP2      LCDDATA10bits.SEG10COM3
#define MILLI    LCDDATA8bits.SEG17COM2
#define MEGA     LCDDATA11bits.SEG17COM3
#define AMPS     LCDDATA2bits.SEG20COM0
#define VOLT     LCDDATA5bits.SEG20COM1
#define KILO     LCDDATA8bits.SEG20COM2
#define OHMS     LCDDATA11bits.SEG20COM3
#define S1       LCDDATA2bits.SEG17COM0
#define S2       LCDDATA5bits.SEG17COM1

/**
    Defines: To Turn on a pixel (a segment from a digit or a special character)
*/
#define S1AON    S1A = 1
#define S1BON    S1B = 1
#define S1CON    S1C = 1
#define S1DON    S1D = 1
#define S1EON    S1E = 1
#define S1FON    S1F = 1
#define S1GON    S1G = 1
#define S2AON    S2A = 1
#define S2BON    S2B = 1
#define S2CON    S2C = 1
#define S2DON    S2D = 1
#define S2EON    S2E = 1
#define S2FON    S2F = 1
#define S2GON    S2G = 1
#define S3AON    S3A = 1
#define S3BON    S3B = 1
#define S3CON    S3C = 1
#define S3DON    S3D = 1
#define S3EON    S3E = 1
#define S3FON    S3F = 1
#define S3GON    S3G = 1
#define RCON     RC = 1
#define BATTON   BATT = 1
#define MINUSON  MINUS = 1
#define ACON     AC = 1
#define DHON     DH = 1
#define RHON     RH = 1
#define BC4ON    BC4 = 1
#define DP4ON    DP4 = 1
#define DP3ON    DP3 = 1
#define DP2ON    DP2 = 1
#define MILLION  MILLI = 1
#define MEGAON   MEGA = 1
#define AMPSON   AMPS = 1
#define VOLTON   VOLT = 1
#define KILOON   KILO = 1
#define OHMSON   OHMS = 1
#define S1ON     S1 = 1
#define S2ON     S2 = 1

/**
    Defines: To Turn off a pixel (a segment from a digit or a special character)
*/
#define S1AOFF    S1A = 0
#define S1BOFF    S1B = 0
#define S1COFF    S1C = 0
#define S1DOFF    S1D = 0
#define S1EOFF    S1E = 0
#define S1FOFF    S1F = 0
#define S1GOFF    S1G = 0
#define S2AOFF    S2A = 0
#define S2BOFF    S2B = 0
#define S2COFF    S2C = 0
#define S2DOFF    S2D = 0
#define S2EOFF    S2E = 0
#define S2FOFF    S2F = 0
#define S2GOFF    S2G = 0
#define S3AOFF    S3A = 0
#define S3BOFF    S3B = 0
#define S3COFF    S3C = 0
#define S3DOFF    S3D = 0
#define S3EOFF    S3E = 0
#define S3FOFF    S3F = 0
#define S3GOFF    S3G = 0
#define RCOFF     RC = 0
#define BATTOFF   BATT = 0
#define MINUSOFF  MINUS = 0
#define ACOFF     AC = 0
#define DHOFF     DH = 0
#define RHOFF     RH = 0
#define BC4OFF    BC4 = 0
#define DP4OFF    DP4 = 0
#define DP3OFF    DP3 = 0
#define DP2OFF    DP2 = 0
#define MILLIOFF  MILLI = 0
#define MEGAOFF   MEGA = 0
#define AMPSOFF   AMPS = 0
#define VOLTOFF   VOLT = 0
#define KILOOFF   KILO = 0
#define OHMSOFF   OHMS = 0
#define S1OFF     S1 = 0
#define S2OFF     S2 = 0

/**
  Section: Interface Routines
*/
        
/**
  @Summary
    Initializes the LCD module

  @Description
    This routine enables LCD module.
    This routine should only be called once during system initialization.    

  @Preconditions
    None.

  @Param
    None.

  @Returns
    None.

  @Example
    <code>
    LCD_Initialize();
    </code>     
*/
void LCD_Initialize (void);

/**
    @Summary
        Enable LCD module
        
    @Description
        This routine enables LCD module.   
        
    @Preconditions
        None.

    @Param
        None.

    @Returns
        None.
      
    @Example
        <code>
        LCD_Enable();
        </code>     
*/
void LCD_Enable (void);

/**
    @Summary
        Disable LCD module
        
    @Description
        This routine disables LCD module.   
        
    @Preconditions
        None.

    @Param
        None.

    @Returns
        None.
      
    @Example
        <code>
        LCD_Disable();
        </code>     
*/
void LCD_Disable (void);

/**
    @Summary
        Enable sleep mode for LCD module
        
    @Description
        This routine enables the sleep mode for LCD module.
        
    @Preconditions
        None.

    @Param
        None.

    @Returns
        None.
      
    @Example
        <code>
        LCD_EnableSleepMode();
        </code>     
*/
void LCD_EnableSleepMode (void);

/**
    @Summary
        Disable sleep mode for LCD module
        
    @Description
        This routine disables the sleep mode for LCD module.
        
    @Preconditions
        None.

    @Param
        None.

    @Returns
        None.
      
    @Example
        <code>
        LCD_DisableSleepMode();
        </code>     
*/
void LCD_DisableSleepMode (void);

/**
    @Summary
        Set contrast for LCD module
        
    @Description
        This routine set the contrast value for LCD module.
        
    @Preconditions
       If The internal reference source bit is 0, then the internal LCDcontrast control is unconnected.

    @Param
        Pass the contrast bits value.
        This range for this value is specific for each device.

    @Returns
        None.
      
    @Example
        <code>
        LCD_SetContrast (value);
        </code>     
*/
void LCD_SetContrast (unsigned int value);

/**
    @Summary
        Set LCD module power mode for A interval.
        
    @Description
        This routine set the LCD module reference ladder A time
        power control.
        
    @Preconditions
        None.

    @Param
        Pass the power bits value.

    @Returns
        None.
      
    @Example
        <code>
        LCD_SetIntervalAPowerMode (value);
        </code>     
*/
void LCD_SetIntervalAPowerMode (unsigned int value);

/**
    @Summary
        Set LCD module power mode for B interval.
        
    @Description
        This routine set the LCD module reference ladder B time
        power control.
        
    @Preconditions
        None.

    @Param
        Pass the power bits value.

    @Returns
        None.
      
    @Example
        <code>
        LCD_SetIntervalBPowerMode (value);
        </code>     
*/
void LCD_SetIntervalBPowerMode (unsigned int value);

/**
    @Summary
        Set LCD module power distribution.
        
    @Description
        This routine set the LCD module power distribution during
        waveform intervals.
        
    @Preconditions
        None.

    @Param
        Pass the power bits value.

    @Returns
        None.
      
    @Example
        <code>
        LCD_SetPowerDistribution (value);
        </code>     
*/
void LCD_SetPowerDistribution (unsigned int value);

/**
    @Summary
        Returns true if the LCD module is active, otherwise false.
        
    @Description
        This routine is used to determine if the LCD module is active.
        
    @Preconditions
        None.

    @Param
        Node.

    @Returns
        true  - If module is active.
        false - If module is not active.
      
    @Example
        <code>
         LCD_Initialize();
         while(!LCD_IsActive()); // wait until the module is available
        </code>     
*/
bool LCD_IsActive (void);

/**
    @Summary
        Return true if the write is disabled. 
        
    @Description
        This method returns the status of WERR bit. This is set when the user attepts to write
        when the write is disabled.
        
    @Preconditions
        None.

    @Param
        Node.

    @Returns
        true  - If the write is disabled and the user attempts to write. 
        false - If everithing works properly. 
      
    @Example
        <code>
   
        </code>     
*/
bool LCD_HasWriteFailureOccurred (void);

/**
    @Summary
        
    @Description
        
    @Preconditions
        None.

    @Param
        Node.

    @Returns
        true  - 
        false - 
      
    @Example
        <code>
   
        </code>     
*/
bool LCD_IsWritingAllowed (void);


/**
  @Summary
    Displays on all the defined pixels for digit no 1

  @Description
    This routine displays on all the defined pixels for digit no 1

  @Returns
    None

  @Param
    None
  
  @Example
        <code>
        void LCD_DisplayOn_S1Num();
        </code>
*/
void LCD_DisplayOn_S1Num();

/**
  @Summary
    Displays off all the defined pixels for digit no 1

  @Description
    This routine displays off all the defined pixels for digit no 1

  @Returns
    None

  @Param
    None
  
  @Example
        <code>
        void LCD_DisplayOff_S1Num();
        </code>
*/
void LCD_DisplayOff_S1Num();    
/**
  @Summary
    Display a char for digit no 1

  @Description
    This routine displays a spefic char for lcd's digit number 1;

  @Returns
    None

  @Param
    The needed char
  
  @Example
        <code>
        void LCD_S1Num ('5');
        </code>      
*/
void LCD_S1Num (unsigned char num);
/**
  @Summary
    Displays on all the defined pixels for digit no 2

  @Description
    This routine displays on all the defined pixels for digit no 2

  @Returns
    None

  @Param
    None
  
  @Example
        <code>
        void LCD_DisplayOn_S2Num();
        </code>
*/
void LCD_DisplayOn_S2Num();

/**
  @Summary
    Displays off all the defined pixels for digit no 2

  @Description
    This routine displays off all the defined pixels for digit no 2

  @Returns
    None

  @Param
    None
  
  @Example
        <code>
        void LCD_DisplayOff_S2Num();
        </code>
*/
void LCD_DisplayOff_S2Num();    
/**
  @Summary
    Display a char for digit no 2

  @Description
    This routine displays a spefic char for lcd's digit number 2;

  @Returns
    None

  @Param
    The needed char
  
  @Example
        <code>
        void LCD_S2Num ('5');
        </code>      
*/
void LCD_S2Num (unsigned char num);
/**
  @Summary
    Displays on all the defined pixels for digit no 3

  @Description
    This routine displays on all the defined pixels for digit no 3

  @Returns
    None

  @Param
    None
  
  @Example
        <code>
        void LCD_DisplayOn_S3Num();
        </code>
*/
void LCD_DisplayOn_S3Num();

/**
  @Summary
    Displays off all the defined pixels for digit no 3

  @Description
    This routine displays off all the defined pixels for digit no 3

  @Returns
    None

  @Param
    None
  
  @Example
        <code>
        void LCD_DisplayOff_S3Num();
        </code>
*/
void LCD_DisplayOff_S3Num();    
/**
  @Summary
    Display a char for digit no 3

  @Description
    This routine displays a spefic char for lcd's digit number 3;

  @Returns
    None

  @Param
    The needed char
  
  @Example
        <code>
        void LCD_S3Num ('5');
        </code>      
*/
void LCD_S3Num (unsigned char num);

/**
  @Summary
    Displays on all the defined pixels for support characters 
    (like the battery symbol)

  @Description
    This routine displays on all the defined pixels for for support 
    characters (like the battery symbol)

  @Returns
    None

  @Param
    None
  
  @Example
        <code>
        void LCD_DisplayOn_SupportingChars();
        </code>
*/
void LCD_DisplayOn_SupportingChars(void);
void LCD_DisplayOFF_SupportingChars(void);

#endif /*_LCD_H*/
