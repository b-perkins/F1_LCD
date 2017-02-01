#include "mcc_generated_files/mcc.h"

void ScreenTest(void);

void main(void)
{
    SYSTEM_Initialize();
    ScreenTest();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();

    while (1)
    {
        asm("NOP");
    }
}

void ScreenTest(void)
{
    while (!LCD_IsWritingAllowed());
    
    LCD_DisplayOn_S1Num();
    LCD_DisplayOn_S2Num();
    LCD_DisplayOn_S3Num();
    LCD_DisplayOn_SupportingChars();
    IO_RD1_Toggle(); // FYI-looks like the rest of the leds in use-LCD
    __delay_ms(1000);
    IO_RD1_Toggle(); 
    LCD_DisplayOFF_SupportingChars();
    LCD_DisplayOff_S3Num();
    LCD_DisplayOff_S2Num();
    LCD_DisplayOff_S1Num();
}