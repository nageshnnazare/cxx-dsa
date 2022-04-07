#include <iostream>

void swap(int* xp, int* yp) {
    *yp = (*xp + *yp) - (*xp = *yp);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void SelectionSort(int arr[], int n) {
    int min_index;
    for (int i = 0; i < n; i++) {
        min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[min_index]) {
                min_index = j;
            }
            swap(&arr[min_index], &arr[j]);
        }
    }
}

int main(int argc, char const* argv[]) {
    int arr[] = { 64, 34, 25, 12, 2, 10, 11 };
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "* " << __FILE__ << " *" << std::endl;
    std::cout << "Before Sorting : " << std::endl;
    printArray(arr, n);

    SelectionSort(arr, n);

    std::cout << "After Sorting : " << std::endl;
    printArray(arr, n);

    return 0;
}