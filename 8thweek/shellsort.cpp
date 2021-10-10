#include <iostream>
#include "SortTestHelper.h"

using namespace std;

void shellSort0(int arr[], int n) {
    int i, j, gap;
    for (gap = n / 2; gap > 0; gap /= 2) {
        for (i = 0; i < gap; i++) {
            for (j = i + gap; j < n; j += gap){
                for (int k = j; k > i && arr[k] < arr[k-gap]; k -= gap){
                    swap(arr[k-gap], arr[k]);
                }
            }
        }
    }
}

void shellSort1(int arr[], int n){
    int i, j ,gap;
    for (gap=n/2; gap > 0; gap /= 2){
        for(i = 0; i < gap; i++){
            for (j = i+gap; j<n; j += gap){
                int tmp = arr[j];
                int k;
                for(k = j; k > i && arr[k-gap] > tmp; k -= gap)
                    arr[k] = arr[k-gap];
                arr[k] = tmp;
            }
        }
    }
}

// from liuyubobobo
void shellSort2(int arr[], int n){
    int h = 1;
    while(h < n/2)
        h = 2 * h + 1;

    while(h >= 1){
        for(int i = h; i < n; i++){
            int cur = arr[i];
            int j;
            for (j = i; j >= h && arr[j - h] > cur; j -= h)
                arr[j] = arr[j - h];
            arr[j] = cur;
        }
        h /= 2;
    }
}


int main() {
//    int arr[15] = {4, 6, 3, 2, 1, 5, 10, 6, 12, 9, 11, 15, 13, 18, 20};
    int n = 1000000;
    int *arr = SortTestHelper::genRandomArray(n, 0, n);
    int *arr1 = SortTestHelper::copyArray(arr, n);
    int *arr2 = SortTestHelper::copyArray(arr, n);
    SortTestHelper::testSort("shellsort0", shellSort0, arr, n);
    SortTestHelper::testSort("shellsort1", shellSort1, arr1, n);
    SortTestHelper::testSort("shellsort2", shellSort2, arr2, n);
    return 0;
}
