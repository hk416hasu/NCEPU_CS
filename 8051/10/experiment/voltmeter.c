#include <8051.h>
#include <math.h>
#include "LCD1602.h"
#include "xpt2046.h"
#include "delayxms.h"
#include "timer0.h"

#define sampleNum 8

long sum = 0;
unsigned int each_voltage_val = 0;  // 0 ~ 255 * 0.02V
int effective_voltage_digital = 0;  // 0 ~ 255 * 0.02V
int effective_voltage_analog = 0;   // 0 ~ 5V
char times = 0;

void main() {
    LCD_Init();
    Timer0_Init();
    while (1);
}

void ISR() __interrupt 1 {
    TH0 = (65536 - 2500) >> 8;   // 50hz, 8 sample a cycle
    TL0 = (65536 - 2500) & 0xff; // so 0.0025s

    times++;
    // calculate
    if ( times <= sampleNum ) {
        each_voltage_val = xpt2046_read(xptCommand_XP);
        sum += each_voltage_val * each_voltage_val;
    }
    // output
    if ( times == sampleNum ) {
        effective_voltage_digital = sqrtf(1.0 * (sum/sampleNum));
        LCD_ShowNum(1, 1, effective_voltage_digital, 3);
        LCD_ShowString(1, 4, " * 0.02V");
        sum = 0;
        times = 0;
    }
}
