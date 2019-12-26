#include "stdio.h"

int partition(int *arr, int start, int end) {
    int pivot = arr[end];
    int i = start;
    for (int j = start; j < end; j++) {
        if (arr[j] < pivot) {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
        }
    }
    int tmp = arr[i];
    arr[i] = arr[end];
    arr[end] = tmp;
    return i;
}

void quickSort(int *arr, int start, int end) {
    if (start >= end) return;
    int q = partition(arr, start, end);
    quickSort(arr, start, q-1);
    quickSort(arr, q+1, end);
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
    quickSort(arr, 0, sizeof(arr)/sizeof(int)-1);
    travel(arr, sizeof(arr)/sizeof(int));
	return 0;
}

