#include <iostream>
#include <vector>
#include <cstring>

int mem[100][100]; // >= mem[n+1][W+1]
int t[100][100]; // >= t[n+1][W+1]

// Memoization
int knapsack_mem(std::vector<int> wt, std::vector<int> val, int W, int n) {
    if (n == 0 || W == 0) {
        return 0;
    }
    if (mem[n][W] != -1) {
        return mem[n][W];
    }

    if (wt[n - 1] <= W) {
        mem[n][W] = std::max(val[n - 1] + knapsack_mem(wt, val, W - wt[n - 1], n - 1),
            knapsack_mem(wt, val, W, n - 1));
        return mem[n][W];
    }
    else if (wt[n - 1] > W) {
        mem[n][W] = knapsack_mem(wt, val, W, n - 1);
        return mem[n][W];
    }
    return 0;
}

// Top-down Approach
int knapsack_td(std::vector<int> wt, std::vector<int> val, int W, int n) {
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
                t[i][j] = std::max(val[i - 1] + t[i - 1][j - wt[i - 1]], t[i - 1][j]);
            }
            else if (wt[i - 1] > j) {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][W];
}


int main(int argc, char const* argv[]) {
    std::vector <int> weight = { 1,3,4,5 };
    std::vector <int> value = { 1,4,5,7 };

    int output_mem = 0, output_td;
    memset(mem, -1, sizeof(mem));

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

    output_mem = knapsack_mem(weight, value, 7, weight.size());
    output_td = knapsack_td(weight, value, 7, weight.size());
    {
        std::cout << "\nOutput :\n";
        std::cout << "Memoization = " << output_mem << "\n";
        std::cout << "Top-Down = " << output_td << "\n";
    }

    return 0;
}
