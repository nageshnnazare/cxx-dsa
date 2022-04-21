#include <iostream>
#include <vector>
#include <cstring>

int static t[100][100];

int solveMCM(std::vector<int> nums, int i, int j) {
    if (i >= j) {
        return 0;
    }

    if (t[i][j] != -1) {
        return t[i][j];
    }

    static int ans = INT32_MAX;

    for (int k = i; k <= j - 1; k++) {
        int temp = solveMCM(nums, i, k)
            + solveMCM(nums, k + 1, j)
            + (nums[i] * nums[k] * nums[j]);
        ans = std::min(ans, temp);
    }
    return t[i][j] = ans;
}

int main(int argc, char const* argv[]) {

    std::vector<int> arr = { 40,20,30,10,30 };

    std::cout << "\nInput : ";
    for (auto itr : arr) {
        std::cout << itr << " ";
    }

    memset(t, -1, sizeof(t));

    int output_td = solveMCM(arr, 1, arr.size() - 1);

    std::cout << "\nOutput : "
        << output_td << std::endl;

    return 0;
}
