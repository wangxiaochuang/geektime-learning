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

int findK(int *arr, int start, int end, int K) {
    if (start >= end) return start;
    int q = partition(arr, start, end);
    if (q + 1 == K) {
        return q; 
    }
    if (q + 1 < K) {
        return findK(arr, q+1, end, K);
    } else {
        return findK(arr, start, q-1, K);
    }
}

int main( int argc, char **argv )
{
    int arr[] = {5,7,4,3,39,8,12,44,10};
    int K = 10;
    int res = findK(arr, 0, sizeof(arr)/sizeof(int)-1, K);
    printf("the K element: %d\n", arr[res]);
	return 0;
}

