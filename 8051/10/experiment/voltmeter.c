#include <8051.h>
#include <math.h>
#include "LCD1602.h"
#include "xpt2046.h"
#include "delayxms.h"

#define sampleNum 8

void main() {
    // initialize
    LCD_Init();
    long sum = 0;
    int each_voltage_val = 0;   // 0 ~ 255
    int effective_voltage_digital = 0;  // 0 ~ 255
    int effective_voltage_analog = 0;   // 0 ~ 5V

    // sample, calculate and output
    while (1) {
        // sample and calculate
        for ( int i = 0; i < sampleNum; i++ ) {
            each_voltage_val = xpt2046_read(xptCommand_XP);
            sum += each_voltage_val * each_voltage_val;
        }

        effective_voltage_digital = sqrtf(1.0 * (sum/sampleNum));
        effective_voltage_analog = (effective_voltage_digital * 5) >> 8;

        // output
        LCD_ShowNum(1, 1, effective_voltage_analog, 1);
        LCD_ShowChar(1, 2, 'V');

        // update
        sum = 0;
        delayxms(10);
    }
}
