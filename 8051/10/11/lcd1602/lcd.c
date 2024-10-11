#include <8051.h>
#include "LCD1602.h"

int main() {
    LCD_Init();
    while (1) {
        LCD_ShowString(1, 1, "hello world!");
    }
}
