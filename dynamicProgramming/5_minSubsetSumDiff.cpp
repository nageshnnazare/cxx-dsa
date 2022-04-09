#include <iostream>
#include <vector>
#include <numeric>

std::vector<int> subsetSum(std::vector<int> arr, int sum, int n) {
    bool t[n + 1][sum + 1]; // t[n+1][sum+1]
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < sum + 1; j++) {
            if (i == 0) {
                t[i][j] = false;
            }
            if (j == 0) {
                t[i][j] = true;
            }
        }
    }

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < sum + 1; j++) {
            if (arr[i - 1] <= j) {
                t[i][j] = (t[i - 1][j - arr[i - 1]]) || (t[i - 1][j]);
            }
            else if (arr[i - 1] > j) {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    std::vector<int> v;
    for (int j = 0; j <= sum; j++) {
        if (t[n][j] == true) {
            v.push_back(j);
        }
    }
    return v;
}

int minSubsetSumDiff(std::vector<int> arr, int n) {

    int mn = INT32_MAX;
    int range = std::accumulate(arr.begin(), arr.end(), 0);

    std::vector<int> v = subsetSum(arr, n, range);

    for (int i = 0; i < v.size(); i++) {
        mn = std::min(mn, abs(range - 2 * arr[i]));
    }
    return mn;
}


int main(int argc, char const* argv[]) {
    std::vector <int> arr = { 1,6,11,5 };

    int output_td;

    {
        std::cout << "\nArr :\n";
        for (auto itr : arr)
            std::cout << itr << "\t";
    }

    output_td = minSubsetSumDiff(arr, arr.size());
    {
        std::cout << "\nOutput :\n";
        std::cout << "Top-Down = " << output_td << "\n";
    }

    return 0;
}