#include <iostream>
#include <vector>

bool searchInMatrix(std::vector<std::vector<int>>& matrix, int target) {
    int lo = 0;
    if (!matrix.size()) return false;
    int hi = (matrix.size() * matrix[0].size()) - 1;

    while (lo <= hi) {
        int mid = (lo + (hi - lo) / 2);
        if (matrix[mid / matrix[0].size()][mid % matrix[0].size()] == target) {
            return true;
        }
        if (matrix[mid / matrix[0].size()][mid % matrix[0].size()] < target) {
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }
    return false;
}

int main(int argc, char const* argv[]) {
    std::vector<std::vector<int>> mat = { {1,2,3}, {4,5,6}, {7,8,9} };
    int target = 5;
    {
        std::cout << "Matrix : " << std::endl;
        for (auto& i : mat) {
            for (auto& j : i) {
                std::cout << j << " ";
            }
            std::cout << std::endl;
        }
        std::cout << "Target : " << target << std::endl;
    }

    std::cout << "Result : " << std::boolalpha << searchInMatrix(mat, 5) << std::endl;

    return 0;
}
