#include <iostream>
#include <vector>

int maxSumOfSubarray(std::vector<int> nums, int k) {
    int sum = 0, i = 0, j = 0;
    int maxSum = 0;
    while (j < nums.size()) {
        sum += nums[j];
        if (j - i + 1 < k) {
            j++;
        }
        else if (j - i + 1 == k) {
            maxSum = std::max(maxSum, sum);
            sum -= nums[i];
            i++; j++;
        }
    }
    return maxSum;
}


int main(int argc, char const* argv[]) {
    std::vector<int> input = { 2,5,1,8,2,9,4,6 };
    int output = 0;

    {
        std::cout << "\nInput :\n";
        for (auto itr : input)
            std::cout << itr << "\t";
    }

    output = maxSumOfSubarray(input, 3);

    {
        std::cout << "\nOutput :\n";
        std::cout << output << "\n";
    }

    return 0;
}

