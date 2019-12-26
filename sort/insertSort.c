#include "stdio.h"

void insertSort(int *arr, int len) {
    for (int i = 1; i < len; i++) {
        int tmp = arr[i]; 
        int j = i;
        for (; j > 0; j--) {
            if (tmp < arr[j-1]) {
                arr[j] = arr[j-1]; 
            } else {
                break;
            }
        }
        arr[j] = tmp;
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
    insertSort(arr, sizeof(arr)/sizeof(int));
    travel(arr, sizeof(arr)/sizeof(int));
	return 0;
}

