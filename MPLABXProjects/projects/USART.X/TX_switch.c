/* program to transmit a string when a switch is pressed
 * File:   TX_switch.c
 * Author: tashi
 *
 * Created on 26 July, 2017, 8:20 AM
 */


// PIC16F876A Configuration Bit Settings

// 'C' source line config statements

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

#include <xc.h>

void send(char *);
void main()
{
    TXSTA=0X24;
    RCSTA=0X90;
    TRISB=0X07;
    SPBRG=25;
    while(1)
    {
        if(RB0==0)
        {
            while(RB0==0);
            send("You have pressed switch 1");
        }
        
    }
}

void send(char *p)
{
    int i;
    for(i=0;*(p+i)!='\0';i++)
    {
        TXREG=*(p+i);
        while(TRMT==0);
        TRMT=0;

        }
}









