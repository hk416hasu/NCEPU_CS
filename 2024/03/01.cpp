// 本代码中除法直接截取整数，不进位
#include <iostream>

void func(int day, int &num1, int &num2) {
    if (day == 1) { return; }

    num1 = (num1 + 1) << 1;
    num2 = (num2 + 1) << 1;
    return func(day-1, num1, num2);
}

void HowManyApple(int day) {
    if (day < 1) { 
        printf("Invalid input.\n");
        return;
    }

    int NumOfApple_1 = 1, NumOfApple_2 = 2;
    func(day, NumOfApple_1, NumOfApple_2);
    printf("%d or %d\n", NumOfApple_1, NumOfApple_2);
}

int main() {

    int day = 0;    // 猴王day天吃完苹果
    scanf("%d", &day);
    HowManyApple(day);

    system("pause");
    return 0;
}