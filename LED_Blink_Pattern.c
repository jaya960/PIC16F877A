
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


void main()
{
    TRISD = 0xDD;  // 1101 1101 RD1 & RD5 as output LEDs and all the rest as input bits
    while(1)
    {
        PORTD = 0x20; //0010 0000 RD5 - ON ; RD1 - OFF
        __delay_ms(3000); // delay of 3 sec
        PORTD = 0x00; // 0000 0000 RD5 - OFF ; RD1 - OFF
        __delay_ms(3000); // delay of 3 sec
        PORTD = 0x02; //0000 0010 RD5 - OFF ; RD1 - ON
        __delay_ms(3000); // delay of 3 sec
        PORTD = 0x22; ///0010 0010 RD5 - ON; RD1 - ON
        __delay_ms(3000); // delay of 3 sec
    }
}
