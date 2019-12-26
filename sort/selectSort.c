#include "stdio.h"

void selectSort(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        int min = i;
        for (int j = i; j < len; j++) {
             if (arr[j] < arr[min]) min = j;
        }
        int tmp = arr[i];
        arr[i] = arr[min];
        arr[min] = tmp;
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
    selectSort(arr, sizeof(arr)/sizeof(int));
    travel(arr, sizeof(arr)/sizeof(int));
	return 0;
}

