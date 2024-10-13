#include <stdio.h>

void swap(int *x, int *y) {
    *x = (*x) ^ (*y);
    *y = (*x) ^ (*y);
    *x = (*x) ^ (*y);
}

int main() {
    
    int arr[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
    int len = sizeof(arr) / sizeof(arr[0]);

    // increasing
    for ( int i = 0; i < len; i++ ) {
        for ( int j = 1; j < len; j++ ) {
            if ( arr[j-1] > arr[j] ) {
                swap(&arr[j-1], &arr[j]);
            }
        }
    }

    for ( int i = 0; i < len; i++ ) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
