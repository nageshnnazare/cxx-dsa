#include <iostream>
#include <vector>
#include <cstring>

int knapsack_unbounded(std::vector<int> wt, std::vector<int> val, int W, int n) {
    int t[n + 1][W + 1];
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < W + 1; j++) {
            if (i == 0 || j == 0) {
                t[i][j] = 0;
            }
        }
    }

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < W + 1; j++) {
            if (wt[i - 1] <= j) {
                t[i][j] = std::max(val[i - 1] + t[i][j - wt[i - 1]], t[i - 1][j]);
            }
            else if (wt[i - 1] > j) {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][W];
}


int main(int argc, char const* argv[]) {
    std::vector <int> weight = { 1,3,4,5 }; // len
    std::vector <int> value = { 1,4,5,7 };  // price

    int output_td;

    {
        std::cout << "\nWeight :\n";
        for (auto itr : weight)
            std::cout << itr << "\t";
    }
    {
        std::cout << "\nValue :\n";
        for (auto itr : value)
            std::cout << itr << "\t";
    }

    output_td = knapsack_unbounded(weight, value, 7, weight.size());
    {
        std::cout << "\nOutput :\n";
        std::cout << "Top-Down = " << output_td << "\n";
    }

    return 0;
}
