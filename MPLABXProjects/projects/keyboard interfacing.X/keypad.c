/*program to inter face a 4*4 keypad,get charecter and display it on 16*2 lcd display
 * File:   keypad.c
 * Author: tashi
 *
 * Created on 5 August, 2017, 9:10 AM
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

#include <xc.h>

#define _XTAL_FREQ 4000000
#define RS RC0
#define RW RC1
#define E RC2

void command(char);
void data(char);
void init();
char keypad();

void main(void) 
{
    char a;
    init();
    while(1)
    {
        a=keypad();
        data(a);
    }
    
}

void command(char a)
{
    char b;
    RS=0;
    RW=0;
    b=a&0XF0;
    PORTC=PORTC&0X0F;
    PORTC=PORTC|b;
    E=1;
    __delay_us(20);
    E=0;
    b=a&0X0F;
    PORTC=PORTC&0X0F;
    PORTC=PORTC|(b<<4);
    E=1;
    __delay_us(20);
    E=0;
}

void data(char a)
{
    char b;
    RS=1;
    RW=0;
    b=a&0XF0;
    PORTC=PORTC&0X0F;
    PORTC=PORTC|b;
    E=1;
    __delay_us(20);
    E=0;
    b=a&0X0F;
    PORTC=PORTC&0X0F;
    PORTC=PORTC|(b<<4);
    E=1;
    __delay_us(20);
    E=0;
}

void init()
{
    command(0X28);
    command(0X2C);
    command(0X01);
    command(0X02);
    command(0X80);
}

char keypad()
{
    RB0=0;RB1=1;RB2=1;RB3=1;
    while(1)
    {
        if(RB0==0)
        {
            if(RB4==0){while(RB4==0);return'0';}
            if(RB5==0){while(RB5==0);return'1';}
            if(RB6==0){while(RB6==0);return'2';}
            if(RB7==0){while(RB7==0);return'3';}
            RB0=1;RB1=0;RB2=1;RB3=1;
        }
        
        if(RB1==0)
        {
            if(RB4==0){while(RB4==0);return'4';}
            if(RB5==0){while(RB5==0);return'5';}
            if(RB6==0){while(RB6==0);return'6';}
            if(RB7==0){while(RB7==0);return'7';}
            RB0=1;RB1=1;RB2=0;RB3=1;
        }
        
        if(RB2==0)
        {
            if(RB4==0){while(RB4==0);return'8';}
            if(RB5==0){while(RB5==0);return'9';}
            if(RB6==0){while(RB6==0);return'A';}
            if(RB7==0){while(RB7==0);return'B';}
            RB0=1;RB1=1;RB2=1;RB3=0;
        }
        
        if(RB3==0)
        {
            if(RB4==0){while(RB4==0);return'C';}
            if(RB5==0){while(RB5==0);return'D';}
            if(RB6==0){while(RB6==0);return'E';}
            if(RB7==0){while(RB7==0);return'F';}
            RB0=0;RB1=1;RB2=1;RB3=1;
        }
    }
}