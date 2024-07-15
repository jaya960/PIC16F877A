
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

unsigned char val; // can be removed and PORTB can be used directly in switch expression

void main()
{
    TRISB = 0xF0;  // 1111 0000 RB4 to RB7 as input pins (switches) and RB0 to RB3 as output pins
    TRISC = 0x00;  // 0000 0000 RC0 to RC7 as output pins (RC1 & RC5 - LEDs)
    PORTC = 0x00;  // 0000 0000 All output pins are initialized to 0s 
    PORTB = 0x00;  // 0000 0000 RB4 to RB7 are not accepted by software since they are input pins (can be taken anyway here); RB0 to RB3 output pins are initialized to 0
    while(1)
    {
        val = PORTB;
        switch(val)
        {
            case 0xE0 : PORTC = 0x02; // 0000 0010 RC1 - ON ; RC5 - OFF
                break;
            case 0xD0 : PORTC = 0x22; // 0010 0010 RC1 - ON ; RC5 - ON
                break;
            case 0xB0 : PORTC = 0x20; // 0010 0000 RC1 - OFF ; RC5 - ON
                break;
            case 0x70 : PORTC = 0x00; // 0000 0000 RC1 - OFF ; RC5 - OFF
                break;
            case 0xF0: PORTC = 0x00; // 0000 0000 RC1 - OFF ; RC5 - OFF (DEFAULT CASE)
                break;
        }
    }
}
