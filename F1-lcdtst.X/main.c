#include "mcc_generated_files/mcc.h"
uint8_t whichNum, digitPos = 0x00;

void main(void)
{
    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();

    while (1)
    {
        asm("NOP");
    }
}

// We will show up here every 1 second
void Tmr6_CallBack_writer(void)
{
    while (!LCD_IsWritingAllowed());
    
    switch (digitPos)
    {
        case 0x00:
            if (whichNum >= 0x10)
            {
                whichNum = 0x00;
                digitPos = 0x01;
            }
                
            LCD_S1Num (whichNum++);
            LCD_DisplayOff_S2Num();
            break;
            
        case 0x01:
            if (whichNum >= 0x10)
            {
                whichNum = 0x00;
                digitPos = 0x00;
            }
                
            LCD_S2Num (whichNum++);
            LCD_DisplayOff_S1Num();
            break;
            
        default: 
            LCD_S1Num (whichNum++);
    }
}