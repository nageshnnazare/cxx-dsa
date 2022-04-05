#include <iostream>
#include <vector>

int largestSubarrayLen(std::vector<int> nums, int k) {
    int i = 0, j = 0;
    int sum = 0, maxlen = 0;
    while (j < nums.size()) {
        sum += nums[j];
        if (sum < k) {
            j++;
        }
        else if (sum == k) {
            maxlen = std::max(maxlen, j - i + 1);
            j++;
        }
        else {
            while (sum > k) {
                sum -= nums[i];
                i++;
            }
            j++;
        }
    }
    return maxlen;
}

int main(int argc, char const* argv[]) {
    std::vector<int> input = { 4,1,1,1,2,3,5 };
    int output;

    {
        std::cout << "\nInput :\n";
        for (auto itr : input)
            std::cout << itr << "\t";
    }

    output = largestSubarrayLen(input, 5);

    {
        std::cout << "\nOutput :\n";
        std::cout << output << "\t";
    }

    return 0;
}