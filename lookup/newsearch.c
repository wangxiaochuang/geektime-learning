#include "stdio.h"

int findFirstEq(int *arr, int start, int end, int target) {
    while (start <= end) {
        int middle = start + ((end - start) >> 1);
        if (arr[middle] < target) {
            start = middle + 1; 
        } else if (arr[middle] > target) {
            end = middle - 1; 
        } else {
            if (middle == 0 || arr[middle-1] != target) {
                return middle;
            } else {
                end = middle - 1;
            }
        }
    }
    return -1;
}

int findLastEq(int *arr, int start, int end, int target) {
    while (start <= end) {
        int middle = start + ((end - start) >> 1);
        if (arr[middle] < target) {
            start = middle + 1; 
        } else if (arr[middle] > target) {
            end = middle - 1;
        } else {
            if (middle == end || arr[middle+1] != target) {
                return middle;
            } else {
                start = middle + 1; 
            }
        }
    }
    return -1;
}
int findLastLe(int *arr, int start, int end, int target) {
    while (start <= end) {
        int middle = start + ((end - start) >> 1);
        if (arr[middle] > target) {
            end = middle - 1; 
        } else {
            if (middle == end || arr[middle+1] > target) {
                return middle; 
            } else {
                start = middle + 1;
            }
        }
    }
    return -1;
}
int findFirstGe(int *arr, int start, int end, int target) {
    while (start <= end) {
        int middle = start + ((end - start) >> 1);
        if (arr[middle] < target) {
            start = middle + 1;
        } else {
            if (middle == end || arr[middle-1] < target) {
                return middle; 
            } else {
                end = middle - 1; 
            }
        }
    }
    return -1;
}

int main( int argc, char **argv )
{
    int arr[] = {1,3,4,5,6,8,8,8,11,18};
    int target = 8;
    //int res = findFirstEq(arr, 0, sizeof(arr)/sizeof(int)-1, target);
    //int res = findLastEq(arr, 0, sizeof(arr)/sizeof(int)-1, target);
    target = 7;
    //int res = findFirstGe(arr, 0, sizeof(arr)/sizeof(int)-1, target);
    target = 9;
    int res = findLastLe(arr, 0, sizeof(arr)/sizeof(int)-1, target);
    printf("the element index: %d\n", res);
	return 0;
}

