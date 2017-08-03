/*project to display a string on a 16*2 lcd display
 * File:   singlecharecter_display.c
 * Author: tashi
 *
 * Created on 3 August, 2017, 7:54 PM
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
#define RS RC0
#define RW RC1
#define E RC2

#include <xc.h>
void command(char);
void data(char);
void init();
void display(char *);

void main(void)
{
   init();
   display("Tashi");
}

void command(char a)
{
    char b;
    RS=0;
    RW=0;
    b=a&0XF0;
    PORTC=PORTC&0X0F;
    PORTC=PORTC&b;
    E=1;
    __delay_us(20);
    E=0;
    b=a&0X0F;
    PORTC=PORTC&0X0F;
    PORTC=PORTC&b;
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
    PORTC=PORTC&b;
    E=1;
    __delay_us(20);
    E=0;
    b=a&0X0F;
    PORTC=PORTC&0X0F;
    PORTC=PORTC&b;
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

void display(char *p)
{
    for(;*p!='\0';p++)
        data(*p);
}
