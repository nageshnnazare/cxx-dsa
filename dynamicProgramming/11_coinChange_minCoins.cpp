#include <iostream>
#include <vector>

int coinChange_minCoins(std::vector<int> wt, int W, int n) {
    int t[n + 1][W + 1];
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < W + 1; j++) {
            if (j == 0) {
                t[i][j] = 0;
            }
            if (i == 0) {
                t[i][j] = INT32_MAX - 1;
            }
            if (i == 1 && j > 0) {
                if (j % wt[0] == 0) {
                    t[i][j] = j / wt[0];
                }
                else {
                    t[i][j] = INT32_MAX - 1;
                }
            }
        }
    }

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < W + 1; j++) {
            if (wt[i - 1] <= j) {
                t[i][j] = std::min(1 + t[i][j - wt[i - 1]], t[i - 1][j]);
            }
            else if (wt[i - 1] > j) {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][W];
}

int main(int argc, char const* argv[]) {
    std::vector <int> coins = { 1,2,3 };

    int output_td;

    {
        std::cout << "\nCoins:\n";
        for (auto itr : coins)
            std::cout << itr << "\t";
    }

    output_td = coinChange_minCoins(coins, 5, coins.size());
    {
        std::cout << "\nOutput :\n";
        std::cout << "Top-Down = " << output_td << "\n";
    }

    return 0;
}