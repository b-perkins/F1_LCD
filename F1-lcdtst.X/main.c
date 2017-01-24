#include "mcc_generated_files/mcc.h"
uint8_t whichNum = 0x00;
void main(void)
{
    SYSTEM_Initialize();
    //INTERRUPT_GlobalInterruptEnable();
    //INTERRUPT_PeripheralInterruptEnable();

    while (1)
    {
        if (LCD_IsWritingAllowed()){
            LCD_DisplayOn_S1Num();
            LCD_DisplayOn_S2Num();
            LCD_DisplayOn_S3Num();
            LCD_DisplayOn_SupportingChars();
            IO_RD1_Toggle(); // FYI-looks like the rest of the leds in use-LCD
        }
    }
}