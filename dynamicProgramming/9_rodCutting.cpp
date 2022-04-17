#include <iostream>
#include <vector>
#include <cstring>

int rodCutting(std::vector<int> length, std::vector<int> price, int N, int n) {
    int t[n + 1][N + 1];
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < N + 1; j++) {
            if (i == 0 || j == 0) {
                t[i][j] = 0;
            }
        }
    }

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < N + 1; j++) {
            if (length[i - 1] <= j) {
                t[i][j] = std::max(price[i - 1] + t[i][j - length[i - 1]], t[i - 1][j]);
            }
            else if (length[i - 1] > j) {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][N];
}


int main(int argc, char const* argv[]) {
    std::vector <int> lengths = { 1,3,4,5 };
    std::vector <int> prices = { 1,4,5,7 };

    int output_td;

    {
        std::cout << "\nLengths :\n";
        for (auto itr : lengths)
            std::cout << itr << "\t";
    }
    {
        std::cout << "\nPrices :\n";
        for (auto itr : prices)
            std::cout << itr << "\t";
    }

    output_td = rodCutting(lengths, prices, 7, lengths.size());
    {
        std::cout << "\nOutput :\n";
        std::cout << "Top-Down = " << output_td << "\n";
    }

    return 0;
}
