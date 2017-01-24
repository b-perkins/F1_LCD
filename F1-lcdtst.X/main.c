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
            BATTON; MINUSON; ACON; X04ON; X05ON; X06ON; X07ON; X08ON;
            X09ON; X10ON; X11ON; X12ON; X13ON; X14ON; X15ON; RCON;
            IO_RD1_Toggle();
        }
    }
}