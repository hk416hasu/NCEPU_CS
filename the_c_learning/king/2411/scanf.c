#include <stdio.h>

void test_1();
void test_2();
void test_3();
void test_4();
void test_5();

int main() {


    return 0;
}

/*
   * brief : check the Assignment-Suppression *
   * input : 1 2
   * output: 2
   * conclusion: the * tells scanf() to read the input but not store it in a variable
   */
void test_6() {
    int num = 0;
    scanf("%*d          %d", &num);
    printf("%d\n", num);
}

/*
   * brief : check the working way of scanf()
   * conclusion: scanf will ignore the previous multi-space,
        and it work as a "string matching func", our conversion-
        specifier tells it how to match input
   */
void test_5() {
    int arr[2] = {0};

    arr[0] = 0; arr[1] = 0;
    scanf("%d%d", &arr[0], &arr[1]);
    printf("%d, %d\n", arr[0], arr[1]);

    arr[0] = 0; arr[1] = 0;
    scanf("%d %d", &arr[0], &arr[1]);
    printf("%d, %d\n", arr[0], arr[1]);

    arr[0] = 0; arr[1] = 0;
    scanf("%d,%d", &arr[0], &arr[1]);
    printf("%d, %d\n", arr[0], arr[1]);
}

/*
   * brief : check the exceed behaviour (%d -> short, is wrong)
   * input : 32768
   * output: 
        -32768
        *** stack smashing detected ***: terminated
        Aborted (core dumped)
   * conclusion: it will be terminated, but we should focus on the boarder
   */
void test_4() {
    short num = 0;
    scanf("%hd", &num); // gcc tells me to use the match conversion specifier with a "type modifier"
    // similarily, %ld -> long integer, %hd -> short integer
    // scanf("%d", &num); // this will exceed, and gcc will warn
    printf("%d\n", num);
}

/*
   * brief : test %width and sscanf()
   * input : NULL(don't need input)
   * output: 5 14 893 0 0
   * conclusion: the "width" limit the "upper" of input, 
                    and when no input, it will assign 0
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

