#include <iostream>
#include <vector>

void setMatrixZeros(std::vector<std::vector<int>>& matrix) {
    int col0 = 1, rows = matrix.size(), cols = matrix[0].size();
    for (int i = 0; i < rows; i++) {
        if (matrix[i][0] == 0) {
            col0 = 0;
        }
        for (int j = 1; j < cols; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = matrix[0][j] = 0;
            }
        }
    }

    for (int i = rows - 1; i >= 0; i--) {
        for (int j = cols - 1; j >= 1; j--) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
        if (col0 == 0) {
            matrix[i][0] = 0;
        }
    }
}

int main(int argc, char const* argv[]) {

    std::vector<std::vector<int>> input = { {1, 2, 0}, {3, 4, 5}, {0, 6, 7} };

    {
        std::cout << "Input : " << std::endl;
        for (auto& i : input) {
            for (auto& j : i) {
                std::cout << j << " ";
            }
            std::cout << std::endl;
        }
    }

    setMatrixZeros(input);

    {
        std::cout << "Output : " << std::endl;
        for (auto& i : input) {
            for (auto& j : i) {
                std::cout << j << " ";
            }
            std::cout << std::endl;
        }
    }

    return 0;
}
