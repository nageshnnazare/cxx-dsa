#include <iostream>
#include <cmath>

void merge(int ar1[], int ar2[], int n, int m) {
    int gap = std::ceil((float)(n + m) / 2);
    while (gap > 0) {
        int i = 0;
        int j = gap;
        while (j < (n + m)) {
            if (j < n && ar1[i] > ar1[j]) {
                std::swap(ar1[i], ar1[j]);
            }
            else if (j >= n && i < n && ar1[i] > ar2[j - n]) {
                std::swap(ar1[i], ar2[j - n]);
            }
            else if (j >= n && i >= n && ar2[i - n] > ar2[j - n]) {
                std::swap(ar2[i - n], ar2[j - n]);
            }
            j++;
            i++;
        }
        if (gap == 1) {
            gap = 0;
        }
        else {
            gap = std::ceil((float)gap / 2);
        }
    }
}

int main(int argc, char const* argv[]) {
    int arr1[] = { 1,4,7,8,10 };
    int arr2[] = { 2,3,9 };
    std::cout << "Before merge:" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;
    merge(arr1, arr2, 5, 3);
    std::cout << "After merge:" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << arr2[i] << " ";
    }

    return 0;
}