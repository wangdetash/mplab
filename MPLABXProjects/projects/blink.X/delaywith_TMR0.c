
/* program to blink all LEDs in PORTB with TMR0IF
 * File:   delaywith_TMR0.c
 * Author: tashi
 *
 * Created on 21 July, 2017, 10:42 AM
 */


// PIC16F876A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = ON        // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>





#include <xc.h>

void main(void) 
{
    TRISB=0X00;
    OPTION_REG=0X87;
    PORTB=0X00;
    while(1)
    {
        PORTB=~PORTB;
        while(TMR0IF==0);
        TMR0IF=0;
    }      
}
