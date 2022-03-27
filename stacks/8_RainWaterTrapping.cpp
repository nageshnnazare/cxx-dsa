#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int maxWater(std::vector<int> nums) {
    std::vector<int> maxLeft;
    std::vector<int> maxRight;
    std::vector<int> water;
    int maxWaterAcc = 0;

    maxLeft.push_back(nums[0]);
    for (int i = 1; i < nums.size(); i++) {
        maxLeft.push_back(std::max(maxLeft[i - 1], nums[i]));
    }

    maxRight.push_back(nums[nums.size() - 1]);
    for (int j = 1; j < nums.size(); j++) {
        maxRight.push_back(std::max(maxRight[j - 1], nums[nums.size() - 1 - j]));
    }
    std::reverse(maxRight.begin(), maxRight.end());

    for (int i = 0; i < nums.size(); i++) {
        water.push_back(std::min(maxLeft[i], maxRight[i]) - nums[i]);
    }

    maxWaterAcc = std::accumulate(water.begin(), water.end(), 0);

    return maxWaterAcc;
}


int main(int argc, char const* argv[]) {
    std::vector<int> input = { 3,0,6,2,0,4 };

    std::cout << "\nInput :\n";
    for (int i = 0; i < input.size(); i++)
        std::cout << input[i] << "\t";

    std::cout << "\n";
    int output = maxWater(input);

    std::cout << "\nOutput :\n" << output << "\n";
    return 0;
}