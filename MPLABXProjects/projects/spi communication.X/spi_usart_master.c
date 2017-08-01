/*master program to transmit a charecter to a slave using spi protocol
 * File:   spi_usart_master.c
 * Author: tashi
 *
 * Created on 1 August, 2017, 9:35 AM
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

void main(void)
{
    char a='*';
    TRISC3=0;
    TRISC4=1;
    TRISC5=0;
    SSPSTAT=0X40;
    SSPCON=0X30;
    while(1)
    {
        SSPBUF=a;
        while(SSPIF==0);
        SSPIF=0;
        __delay_ms(200);
    }
    
}
