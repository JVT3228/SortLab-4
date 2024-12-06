#include "SortAlgorithms.h"

void combSort(int arr[], int size) {
    int gap = size;
    bool swapped = true;

    while (gap != 1 || swapped) {
        gap = (gap * 10) / 13;
        if (gap < 1) gap = 1;

        swapped = false;
        for (int i = 0; i < size - gap; ++i) {
            if (arr[i] > arr[i + gap]) {
                std::swap(arr[i], arr[i + gap]);
                swapped = true;
            }
        }
    }
}