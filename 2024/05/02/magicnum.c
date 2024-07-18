#include <stdio.h>

/*
    平方根倒数速算法(32位)
    整体采用牛顿迭代法，使用magicNum算得第0个近似值后，再做精确化处理
*/
float Q_rsqrt( float number )
{
    long i;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = number * 0.5F;
    y  = number;

    i  = * ( long * ) &y; // evil floating point bit level hacking
    i  = 0x5f3759df - ( i >> 1 );  // what the fuck? 
    y  = * ( float * ) &i;

    // 牛顿迭代法, 使y0更精确
    y  = y * ( threehalfs - ( x2 * y * y ) );  // 1st iteration 
    // 2nd iteration, this can be removed
    // y  = y * ( threehalfs - ( x2 * y * y ) ); 
    return y;
}

int main() {
    float x = 2;
    float y = Q_rsqrt(x);
    printf("%f", y);
    return 0;
}