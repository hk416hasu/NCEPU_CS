// 向内存中写入1..10, 再读出来并累加

int array[10];

main() {
    int index = 0;
    int count = 10;
    int val = 1;
    while( count != 0 ) {
        array[index] = val;
        index = index + 1;
        val = val + 1;
        count = count - 1;
    }

    int sum = 0;
    count = 10;
    index = 0;
    val = 0;
    while( count != 0 ) {
        val = array[index];
        sum = sum + val;
        index = index + 1;
        count = count - 1;
    }

}