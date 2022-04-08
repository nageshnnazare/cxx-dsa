#include <iostream>
#include <vector>

int countOfSubsets(std::vector<int> arr, int sum, int n) {
    int t[n + 1][sum + 1]; // t[n+1][sum+1]
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < sum + 1; j++) {
            if (i == 0) {
                t[i][j] = 0;
            }
            if (j == 0) {
                t[i][j] = 1;
            }
        }
    }

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < sum + 1; j++) {
            if (arr[i - 1] <= j) {
                t[i][j] = (t[i - 1][j - arr[i - 1]]) + (t[i - 1][j]);
            }
            else if (arr[i - 1] > j) {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][sum];
}

int main(int argc, char const* argv[]) {
    std::vector <int> arr = { 2,3,5,6,8,10 };

    int output_td;

    {
        std::cout << "\nArr :\n";
        for (auto itr : arr)
            std::cout << itr << "\t";
    }

    output_td = countOfSubsets(arr, 10, arr.size());
    {
        std::cout << "\nOutput :\n";
        std::cout << "Top-Down = " << output_td << "\n";
    }

    return 0;
}