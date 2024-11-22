#include <stdio.h>

void test_1();
void test_2();
void test_3();

int main() {

    test_3();

    return 0;
}

/*
   * brief : test %width and sscanf()
   * input : NULL(don't need input)
   * output: 5 14 893 0 0
   * conclusion: the width limit the "upper" of input, and when no input, 
   *                it will assign 0
   */
void test_2() {
    char str[10] = "514893";
    int arr[5] = {0};
    sscanf(str, "%1d%2d%3d%1d%1d", &arr[0], &arr[1], &arr[2],
            &arr[3], &arr[4]);
    for (int i = 0; i < 5; i++) {
        printf("%d\n", arr[i]);
    }
}

/*
   * brief : test %[
   * input : Ai51c6
   * output: Ai
   * conclusion: it only accept alpha character, and return when meet others
   */
void test_3() {
    char str[10] = {0};
    scanf("%[a-zA-Z]", str);
    printf("%s\n", str);
}

/*
   * brief : test how scanf work
   * input : 10.3 5 6
   * output: 10 0.300000 5
   * conclusion: scanf will work like to "match" target as long as possible
   */
void test_1() {
    int i, k;
    float j;

    scanf("%d%f%d", &i, &j, &k); // 10.3 5 6
    printf("i = %d\nj = %f\nk = %d\n", i, j, k);
}

