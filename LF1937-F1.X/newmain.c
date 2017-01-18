#include <xc.h> // PIC16LF1937 Configuration Bit Settings
#include "LCD_init.h"

int16_t pot_value;
unsigned int temp, isr_count = 1;

void device_init(void);
void lcd_init(void);
int16_t get_adc(uint8_t);
void display_pot(int);
char display_int(int);
bool lcd_display_digits(BCD_TYPE);
bool input_button(void);
void interrupt isr();
void test_disp(uint8_t);

void main(void)
{
   device_init();
   while(1){//------------------------- main loop ------------------------------
       while(WA){
           display_pot(temp);//temp is just a value from 0 - 1024. incremented in the isr. 
       }                     //and converted to BCD before being displayed
        LATDbits.LATD1 = !LATDbits.LATD1;
	} //------------------------------- end main loop -------------------------- 	    
}   

void lcd_init(void){
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
    LCDEN = 1;
}

int16_t get_adc(uint8_t channel){
    ADCON0bits.CHS = channel; 
    __delay_us(ACQ_US_DELAY);// Acquisition time delay
    ADCON0bits.GO_nDONE = 1;// Start the conversion
    while (ADCON0bits.GO_nDONE);// Wait for the conversion to finish
    return ((ADRESH << 8) + ADRESL);// Conversion finished, return the result
}

void display_pot(int p){
    display_int(p);
    DP3 = 0;// below: these are the supporting characters
    DP2 = 0;
    S1 = 1;
    S2 = 1;
    AMPS = 0;
    VOLT = 1;
    KILO = 0;
    OHMS = 0;
    MINUS = 0;
    DH = 0;
    RH = 0;
    RC = 0;
    MEGA = 0;
    MILLI = 1;
}

//TODO - currently displaying ADRES, in the future this could reflect the actual voltage
char display_int(int t){
    BCD_TYPE bcd;
    // assumes t is the temperature in degrees C * 10
    bcd.digit0 = t %10;
    t /= 10;
    bcd.digit1 = t % 10;
    t /= 10;
    bcd.digit2 = t % 10;
    t /= 10;
    bcd.digit3 = t%10;
    return(lcd_display_digits(bcd));   
} 

bool lcd_display_digits(BCD_TYPE b)
{
    // Map Digit 3
    uint8_t   val;
// The long list of IF statements was the fastest code as of HITEC 9.65PL1
    if(WA) // make sure it is OK to write the data
    {
        val = segment_data[b.digit0].val;
        if(val & SEG_A)
        {
            A1 = 1;
        }

        if(!(val & SEG_A))
        {
            A1 = 0;
        }

        if(val & SEG_B)
        {
            B1 = 1;
        }

        if(!(val & SEG_B))
        {
            B1 = 0;
        }

        if(val & SEG_C)
        {
            C1 = 1;
        }

        if(!(val & SEG_C))
        {
            C1 = 0;
        }

        if(val & SEG_D)
        {
            D1 = 1;
        }

        if(!(val & SEG_D))
        {
            D1 = 0;
        }

        if(val & SEG_E)
        {
            E1 = 1;
        }

        if(!(val & SEG_E))
        {
            E1 = 0;
        }

        if(val & SEG_F)
        {
            F1 = 1;
        }

        if(!(val & SEG_F))
        {
            F1 = 0;
        }

        if(val & SEG_G)
        {
            G1 = 1;
        }

        if(!(val & SEG_G))
        {
            G1 = 0;
        }

        val = segment_data[b.digit1].val;
        if(val & SEG_A)
        {
            A2 = 1;
        }

        if(!(val & SEG_A))
        {
            A2 = 0;
        }

        if(val & SEG_B)
        {
            B2 = 1;
        }

        if(!(val & SEG_B))
        {
            B2 = 0;
        }

        if(val & SEG_C)
        {
            C2 = 1;
        }

        if(!(val & SEG_C))
        {
            C2 = 0;
        }

        if(val & SEG_D)
        {
            D2 = 1;
        }

        if(!(val & SEG_D))
        {
            D2 = 0;
        }

        if(val & SEG_E)
        {
            E2 = 1;
        }

        if(!(val & SEG_E))
        {
            E2 = 0;
        }

        if(val & SEG_F)
        {
            F2 = 1;
        }

        if(!(val & SEG_F))
        {
            F2 = 0;
        }

        if(val & SEG_G)
        {
            G2 = 1;
        }

        if(!(val & SEG_G))
        {
            G2 = 0;
        }

        val = segment_data[b.digit2].val;
        if(val & SEG_A)
        {
            A3 = 1;
        }

        if(!(val & SEG_A))
        {
            A3 = 0;
        }

        if(val & SEG_B)
        {
            B3 = 1;
        }

        if(!(val & SEG_B))
        {
            B3 = 0;
        }

        if(val & SEG_C)
        {
            C3 = 1;
        }

        if(!(val & SEG_C))
        {
            C3 = 0;
        }

        if(val & SEG_D)
        {
            D3 = 1;
        }

        if(!(val & SEG_D))
        {
            D3 = 0;
        }

        if(val & SEG_E)
        {
            E3 = 1;
        }

        if(!(val & SEG_E))
        {
            E3 = 0;
        }

        if(val & SEG_F)
        {
            F3 = 1;
        }

        if(!(val & SEG_F))
        {
            F3 = 0;
        }

        if(val & SEG_G)
        {
            G3 = 1;
        }

        if(!(val & SEG_G))
        {
            G3 = 0;
        }

        if(b.digit3 > 0)
        {
            BC4 = 1;
        }
        else
        {
            BC4 = 0;
        }

        return (1);
    }

    return (0);
}

void interrupt isr(){
    if (PIE1bits.TMR1IE && PIR1bits.TMR1IF){
        if (temp >= 0x400)//400 => 1024 decimal
           temp = 0;
        else
            temp++;
       PIR1bits.TMR1IF = 0;
    }   
}

void test_disp(uint8_t dispVal){
    if (dispVal == 0x01)
    {
        A1 = 0;//digit 1
        B1 = 1;
        C1 = 1;
        D1 = 0;
        E1 = 0;
        F1 = 0;
        G1 = 0;
    }
    else
    {
        A1 = 1;//digit 2
        B1 = 1;
        C1 = 0;
        D1 = 1;
        E1 = 1;
        F1 = 0;
        G1 = 1;
    }
    return;
}

void device_init(void){
    //T1CKPS 1:1; T1OSCEN disabled; nT1SYNC do_not_synchronize; TMR1CS External; TMR1ON enabled; 
    T1CON = 0x84;//EXTERNAL OSCILLATOR - ~32KHz

    //T1GSS T1G; TMR1GE disabled; T1GTM disabled; T1GPOL low; T1GGO done; T1GSPM disabled; 
    T1GCON = 0x00;

    //TMR1H 240; 
    TMR1H = 0xF0;

    //TMR1L 0; 
    TMR1L = 0x00;

    // Clearing IF flag.
    PIR1bits.TMR1IF = 0;
    PIE1bits.TMR1IE = 1;

    // Start TMR1
    T1CONbits.TMR1ON = 1;
    
    OSCCON = 0xF0;//attempting to select 32MHz
    PORTC = 0x00;
	PORTD = 0x00;
	PORTE = 0x00;
	TRISCbits.TRISC2 = 0;
	TRISEbits.TRISE0 = 0;//LED D4
	TRISEbits.TRISE1 = 0;//LED D3
	TRISEbits.TRISE2 = 0;//LED D2
	TRISDbits.TRISD1 = 0;//LED D1
    TRISDbits.TRISD2 = 1;//button S1
	TRISDbits.TRISD5 = 0;
	TRISDbits.TRISD6 = 0;
	ANSELAbits.ANSA1 = 1;
	ANSELAbits.ANSA3 = 1;
	ANSELBbits.ANSB3 = 1;
	ANSELBbits.ANSB1 = 1;
    ANSELDbits.ANSD2 = 0;//button S1
    
    //ADC init ------------------------------------
    ADCON0 = 0x01;// GO_nDONE stop; ADON enabled; CHS AN0; 
    ADCON1 = 0x80;// ADFM right; ADNREF VSS; ADPREF VDD; ADCS FOSC/2; 
    ADRESL = 0x00;//clear result reg
    ADRESH = 0x00;
    ADCON0bits.ADON = 1;
    
    lcd_init();
    
    LCDIE = 0;//TODO set again, after testing
	PEIE = 1;//TODO
	GIE = 1;//TODO
    
    // light all segments
	AMPS = 1;
	VOLT = 1;
	KILO = 1;
	OHMS = 1;
	S1 = 1;
	S2 = 1;
	MILLI = 1;
	MEGA = 1;
	B1 = G1 = C1 = 1;
	A1 = F1 = E1 = D1 = 1;
	B2 = G2 = C2 = DP2 = 1;
	D2 = E2 = F2 = A2 = 1;
	DP3 = C3 = G3 = B3 = 1;
	D3 = E3 = F3 = A3 = 1;
	DP4 = BC4 = RH = DH = 1;
	AC = MINUS = BATT = RC = 1;
    
        // wait for LCD ready
	while(!WA);
	// clear all segments
	AMPS = 0;
	VOLT = 0;
	KILO = 0;
	OHMS = 0;
	S1 = 0;
	S2 = 0;
	MILLI = 0;
	MEGA = 0;
	B1 = G1 = C1 = 0;
	A1 = F1 = E1 = D1 = 0;
	B2 = G2 = C2 = DP2 = 0;
	D2 = E2 = F2 = A2 = 0;
	DP3 = C3 = G3 = B3 = 0;
	D3 = E3 = F3 = A3 = 0;
	DP4 = BC4 = RH = DH = 0;
	AC = MINUS = BATT = RC = 0;
}