/* program to blink all leds on PORTB with delay using TMR1
 * File:   delaywith_TMR1.c
 * Author: tashi
 *
 * Created on 21 July, 2017, 11:09 AM
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
    T1CON=0X31;
    TRISB=0X00;
    PORTB=0XFF;
    int i;
    while(1)
    {
        PORTB=~PORTB;
        for(i=0;i<1000;i++)
        {
            TMR1L=0X82;     //we have found that it takes 1ms to reach 255 from 0X82 from the equation 
            TMR1H=0XFF;
            while(TMR1L<255);
        }
        }
    }
