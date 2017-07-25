//program to blink leds in PORTB using PIC and delay using timer2

/*
 * File:   blink.c
 * Author: tashi
 *
 * Created on 14 July, 2017, 5:27 PM
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


#define _XTAL_FREQ 4000000
// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>

void main()
{
    TRISB=0X00;
    PORTB=0X00;
    int i;
    while(1)
    {
         PORTB=~PORTB;
         for(i=0;i<500;i++)
         {
             TMR2=192;        //from the equatuation we have found that it takes 1ms to reach 255 from 192
             while(TMR2<255);
         }
    }
}
