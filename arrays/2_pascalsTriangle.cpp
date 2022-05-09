#include <iostream>
#include <vector>

std::vector<std::vector<int>> pascalsTriangle(int n) {
    std::vector<std::vector<int>> res(n);

    for (int i = 0; i < n; i++) {
        res[i].resize(i + 1);
        res[i][0] = res[i][i] = 1;

        for (int j = 0; j < i; j++) {
            res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
        }
    }
    return res;
}


int main(int argc, char const* argv[]) {
    int n = 5;
    std::vector<std::vector<int>> result = pascalsTriangle(n);

    for (auto& i : result) {
        for (auto& j : i) {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
