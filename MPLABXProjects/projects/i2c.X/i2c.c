/*Header file for i2c communication
 * File:   i2c.c
 * Author: tashi
 *
 * Created on 7 August, 2017, 9:16 AM
 */

void init()
{
    SSPCON=0X28;
    SSPSTAT=0X80;
    SSPADD=(((_XTAL_FREQ/4000)/100)-1);
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
    return (ACKSTAT);
}

void recieve()
{
    RCEN=1;
    while(SSPIF==0);
    SSPIF=0;
    return(SSPBUF);
}



