#include <iostream>

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (int a = 0; a < n1; a++) {
        L[a] = arr[left + a];
    }

    for (int b = 0; b < n2; b++) {
        R[b] = arr[mid + 1 + b];
    }

    int i = 0, j = 0, k = 1;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main(int argc, char const* argv[]) {
    int arr[] = { 64, 34, 25, 12, 2, 10, 11, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "* " << __FILE__ << " *" << std::endl;
    std::cout << "Before Sorting : " << std::endl;
    printArray(arr, n);

    MergeSort(arr, 0, n - 1);

    std::cout << "After Sorting : " << std::endl;
    printArray(arr, n);

    return 0;
}
