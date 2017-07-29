/*program to change voltage through serial communication with constant duty cycle and varying period
 * File:   pwm_usart.c
 * Author: tashi
 *
 * Created on 29 July, 2017, 7:24 AM
 */
// CONFIG
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.


#define _XTAL_FREQ 4000000

#include<xc.h>

void main()
{
    TXSTA=0X24;
    RCSTA=0X90;
    SPBRG=25;
    TRISC2=0;
    TRISC7=1;
    T2CON=0X07;
    CCP1CON=0X0C;
    PR2=255;
    CCPR1L=0;
    while(1)
    {
        while(RCIF==0);
        RCIF=0;
        while(RCIF=='Q')
        {
            if(CCPR1L<255)
            {
                CCPR1L++;
            }
            
        }
        while(RCIF=='W')
        {
            if(CCPR1L>0)
            {
                CCPR1L--;
            }
            
        }

    }
}