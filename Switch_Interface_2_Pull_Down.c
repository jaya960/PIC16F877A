
// PIC16F877A Configuration Bit Settings

// 'C' source line config statements

// CONFIG
#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
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
#define _XTAL_FREQ 6000000

unsigned char val;
void main()
{
    TRISC = 0x0F; // 0000 1111 RC0 to RC3 as input pins (switches) and RC4 to RC7 as output pins
    TRISD = 0x00; // 0000 0000 RD0 to RD7 as output pins (RD3 & RD4 - LEDs)
    PORTD = 0x00; // 0000 0000 All output pins are initialized to 0s 
    PORTC = 0x00; // 0000 0000 RC0 to RC3 are not accepted by software since they are input pins (can be taken anyway here); RC4 to RC7 output pins are initialized to 0
    while(1)
    {
        val = PORTC;
        switch(val)
        {
            case 0x01 : PORTD = 0x10; // 0001 0000 RD4 - ON & RD2 - OFF
                break;
            case 0x02 : PORTD = 0x04; // 0000 0100 RD4 - OFF & RD2 - ON
                break;
            case 0x04: PORTD = 0x14; // 0001 0100 RD4 - ON & RD2 - ON
                break;
            case 0x08 : PORTD = 0x00; // 0000 0000 RD4 - OFF & RD2 - OFF
                break;
            case 0x00 : PORTD = 0x00; // 0000 0000 RD4 - OFF & RD2 - OFF (DEFAULT CASE)
                break;
        }
    }
}
