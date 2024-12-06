#include "SortAlgorithms.h"
#include <algorithm>

void countingSort(int arr[], int size) {
    int maxElement = *std::max_element(arr, arr + size);
    int minElement = *std::min_element(arr, arr + size);
    int range = maxElement - minElement + 1;

    std::vector<int> count(range, 0);
    std::vector<int> output(size);

    for (int i = 0; i < size; ++i)
        count[arr[i] - minElement]++;

    for (int i = 1; i < range; ++i)
        count[i] += count[i - 1];

    for (int i = size - 1; i >= 0; --i) {
        output[count[arr[i] - minElement] - 1] = arr[i];
        count[arr[i] - minElement]--;
    }

    for (int i = 0; i < size; ++i)
        arr[i] = output[i];
}