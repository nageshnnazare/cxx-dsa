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

void BubbleSort(int arr[], int n) {
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
}

int main(int argc, char const* argv[]) {
    int arr[] = { 64, 34, 25, 12, 2, 10, 11 };
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "* " << __FILE__ << " *" << std::endl;
    std::cout << "Before Sorting : " << std::endl;
    printArray(arr, n);

    BubbleSort(arr, n);

    std::cout << "After Sorting : " << std::endl;
    printArray(arr, n);

    return 0;
}
