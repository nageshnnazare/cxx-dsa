#include <iostream>

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void InsertionSort(int arr[], int n) {
    int key, j;
    for (int i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main(int argc, char const* argv[]) {
    int arr[] = { 64, 34, 25, 12, 2, 10, 11 };
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "* " << __FILE__ << " *" << std::endl;
    std::cout << "Before Sorting : " << std::endl;
    printArray(arr, n);

    InsertionSort(arr, n);

    std::cout << "After Sorting : " << std::endl;
    printArray(arr, n);

    return 0;
}
