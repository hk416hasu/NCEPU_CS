#include <8051.h>
#include "timer0.h"
#include "LCD1602.h"

char sec = 0;
char min = 0;
char hour = 0;

void Clock_Init() {
    hour = 12;
    min = 59;
    sec = 55;
}

void printClock() {
    LCD_ShowNum(1, 1, hour, 2);
    LCD_ShowChar(1, 3, ':');
    LCD_ShowNum(1, 4, min, 2);
    LCD_ShowChar(1, 6, ':');
    LCD_ShowNum(1, 7, sec, 2);
}

int main() {

    Timer0_Init();
    LCD_Init();
    Clock_Init();

    while (1) {
        printClock();
    }
}

char count = 0;
void ISR() __interrupt 1 {
    TH0 = (65536 - 50000) >> 8;
    TL0 = (65536 - 50000) & 0xff;

    count++;
    if ( count == 20 ) {
        count = 0;
        if ( min == 59 && sec == 59 ) {
            hour = (hour + 1) % 24;
        }
        if ( sec == 59 ) {
            min = (min + 1) % 60;
        }
        sec = (sec + 1) % 60;
    }
}
