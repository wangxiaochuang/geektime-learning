#include "stdio.h"
#include "string.h"
#include "stdlib.h"

void merge(int *arr, int start, int middle, int end) {
    int *tmp = (int *) malloc((end - start + 1) * sizeof(int));
    int i = start, j = middle + 1, k = 0;
    while (i <= middle && j <= end) {
        if (arr[i] < arr[j]) {
            tmp[k++] = arr[i++];
        } else {
            tmp[k++] = arr[j++];
        }
    }
    while (i <= middle) {
        tmp[k++] = arr[i++];
    }
    while (j <= end) {
        tmp[k++] = arr[j++];
    }
    memcpy(arr + start, tmp, (end - start + 1) * sizeof(int));
}

void mergeSort(int *arr, int start, int end) {
    if (start >= end) return;
    int middle = (start + end)  / 2;
    mergeSort(arr, start, middle);
    mergeSort(arr, middle+1, end);
    merge(arr, start, middle, end);
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
    mergeSort(arr, 0, sizeof(arr)/sizeof(int)-1);
    travel(arr, sizeof(arr)/sizeof(int));
	return 0;
}


