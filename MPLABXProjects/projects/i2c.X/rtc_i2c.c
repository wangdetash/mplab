/*program to  get time from rtc via i2c protocol display time through usart
 * File:   rtc_i2c.c
 * Author: tashi
 *
 * Created on 2 August, 2017, 7:14 PM
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
#include <stdio.h>

void init();
void start();
void stop();
void restart();
void ack();
void nack();
bit transmit(char );
char recieve();
void send(char *);

void main(void)
{
    char s,m,h,p[20];
    init();
    start();
    while(transmit(0XD0)==1)
    {
        start();
    }
    transmit(0X00);
    transmit(0X16);
    transmit(0X14);
    transmit(0X15);
    stop();
    while(1)
    {
        start();
        while(transmit(0XD0)==1)
        {
            start();
        }
        transmit(0X00);
        restart();
        transmit(0XD1);
        s=recieve();
        ack();
        m=recieve();
        ack();
        h=recieve();
        nack();
        stop();
        sprintf(p,"%x :%x :%x \r",h,m,s);
        send(p);
        __delay_ms(1000);
    }
}


void init()
{
    TRISC3=1;
    TRISC4=1;
    TRISC6=0;
    TRISC7=1;
    SSPCON=0X28;
    SSPSTAT=0X80;
    SSPADD=((_XTAL_FREQ/4000)/100)-1;
    TXSTA=0X24;
    RCSTA=0X90;
    SPBRG=25;
}

void start()
{
    SEN=1;
    while(SSPIF==0);
    SSPIF=0;
}

void stop()
{
    PEN=1;
    while(SSPIF==0);
    SSPIF=0;
}

void restart()
{
    RSEN=1;
    while(SSPIF==0);
    SSPIF=0;
}

void ack()
{
    ACKDT=0;
    ACKEN=1;
    while(SSPIF==0);
    SSPIF=0;
}

void nack()
{
    ACKDT=1;
    ACKEN=1;
    while(SSPIF==0);
    SSPIF=0;
}

bit transmit(char a)
{
    SSPBUF=a;
    while(SSPIF==0);
    SSPIF=0;
    return(ACKSTAT);
}

char recieve()
{
    
    RCEN=1;
    while(SSPIF==0);
    SSPIF=0;
    return(SSPBUF);
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
