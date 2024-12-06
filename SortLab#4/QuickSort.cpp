#include "SortAlgorithms.h"

void quickSortHelper(int arr[], int left, int right) {
    if (left < right) {
        int pivot = arr[right];
        int partitionIndex = left;

        for (int i = left; i < right; ++i) {
            if (arr[i] <= pivot) {
                std::swap(arr[i], arr[partitionIndex]);
                partitionIndex++;
            }
        }
        std::swap(arr[partitionIndex], arr[right]);

        quickSortHelper(arr, left, partitionIndex - 1);
        quickSortHelper(arr, partitionIndex + 1, right);
    }
}

void quickSort(int arr[], int left, int right) {
    quickSortHelper(arr, left, right);
}