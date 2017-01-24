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
            BATTON; MINUSON; ACON; DHON; RHON; BC4ON; DP4ON; DP3ON;
            DP2ON; MILLION; MEGAON; AMPSON; VOLTON; KILOON; OHMSON; RCON;
            IO_RD1_Toggle(); // FYI-looks like the rest of the leds in use-LCD
        }
    }
}