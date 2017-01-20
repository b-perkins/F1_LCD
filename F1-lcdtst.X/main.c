#include "mcc_generated_files/mcc.h"
uint8_t whichNum = 0x00;
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    while (1)
    {
        if (LCD_IsWritingAllowed()){
            LCD_DisplayOn_S1Num();
            LCD_DisplayOn_S2Num();
            LCD_DisplayOn_S3Num();
            X01ON; X02ON; X03ON; X04ON; X05ON; X06ON; X07ON; X08ON;
            X09ON; X10ON; X11ON; X12ON; X13ON; X14ON; X15ON;
            IO_RD1_Toggle();
        }
    }
}