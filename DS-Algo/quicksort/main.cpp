#include <iostream>
#include "quicksort.hpp"

void printArray(int *arr, int size) {
    for (int i=0; i<size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {

    initSeed();
    
    int arr[500];
    int size;

    while (1) {
        std::cin >> size;
        for (int i=0; i<size; i++) {
            std::cin >> arr[i];
        }
        quickSort(arr, 0, size-1);
        printArray(arr, size);
    }

    return 0;
}