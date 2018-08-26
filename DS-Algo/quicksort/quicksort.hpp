#ifndef quicksort_h
#define quicksort_h

#include <cstdlib>
#include <ctime>

void initSeed() {
    srand((int)time(0));
}

void swapElements(int &address1, int &address2) {
    int temp = address1;
    address1 = address2;
    address2 = temp;
}

// Random Partition
int getRandomPartition(int startIndex, int endIndex) { 
    return rand()%((endIndex - startIndex) + 1) + startIndex;
}  

int partitionArray(int *arr, int startIndex, int endIndex) {
    int counter = startIndex;
    int pivot = arr[endIndex];

    for (int i=startIndex; i<endIndex; i++) {
        if (arr[i] <= pivot) {
            swapElements(arr[counter], arr[i]);
            counter += 1;
        }
    }

    swapElements(arr[counter], arr[endIndex]);

    return counter;
}

int createPartition(int *arr, int startIndex, int endIndex) {
    int partition = getRandomPartition(startIndex, endIndex);
    swapElements(arr[partition], arr[endIndex]);
    return partitionArray(arr, startIndex, endIndex);
}

void quickSort(int *arr, int startIndex, int endIndex) {

    if (startIndex < endIndex) {
        int partitionIndex = createPartition(arr, startIndex, endIndex);
        quickSort(arr, startIndex, partitionIndex-1);
        quickSort(arr, partitionIndex+1, endIndex);
    }

}

#endif