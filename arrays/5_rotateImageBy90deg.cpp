#include <iostream>
#include <vector>
#include <algorithm>

void rotate(std::vector < std::vector < int >>& matrix) {
    int n = matrix.size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }

    for (int i = 0; i < n; i++) {
        std::reverse(matrix[i].begin(), matrix[i].end());
    }
}

int main(int argc, char const* argv[]) {
    std::vector<std::vector <int>> arr = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    {
        std::cout << "Original Image : " << std::endl;
        for (auto& i : arr) {
            for (auto& j : i) {
                std::cout << j << " ";
            }
            std::cout << std::endl;
        }
    }

    rotate(arr);
    {
        std::cout << "Rotated Image" << std::endl;
        for (auto& i : arr) {
            for (auto& j : i) {
                std::cout << j << " ";
            }
            std::cout << std::endl;
        }
    }

    return 0;
}