#include "stdio.h"

void bubbleSort(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
}

void travel(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", *(arr+i));
    }
    printf("\n");
}
    
int main( int argc, char **argv )
{
    int arr[] = {5,7,4,3,39,8,12,44,10};
    bubbleSort(arr, sizeof(arr)/sizeof(int));
    travel(arr, sizeof(arr)/sizeof(int));
	return 0;
}

