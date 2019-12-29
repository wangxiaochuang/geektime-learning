#include "stdio.h"

int bfind(int *arr, int start, int end, int target) {
    while (start <= end) {
        int middle = start + ((end - start) >> 1);
        if (arr[middle] == target) return middle;
        if (arr[middle] < target) {
            start = middle + 1; 
        } else {
            end = middle - 1; 
        }
    }
    return -1;
}

int main( int argc, char **argv )
{
    int arr[] = {3,4,5,7,8,10,12,44,39};
    int target = 5;
    int res = bfind(arr, 0, sizeof(arr)/sizeof(int)-1, target);
    printf("the element index: %d\n", res);
	return 0;
}

