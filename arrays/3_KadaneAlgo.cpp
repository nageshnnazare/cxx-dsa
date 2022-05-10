#include <iostream>
#include <vector>

int maxSubarraySum(std::vector<int> nums, std::pair<int, int>& index) {
    int max_so_far = nums[0], max_end_here = 0;
    int s = 0;
    for (int i = 0; i < nums.size(); i++) {
        max_end_here += nums[i];
        if (max_end_here > max_so_far) {
            max_so_far = max_end_here;
            index = std::make_pair(s, i);
        }
        if (max_end_here < 0) {
            max_end_here = 0;
            s = i + 1;
        }
    }
    return max_so_far;
}

int main(int argc, char const* argv[]) {
    std::vector<int> arr{ -2,1,-3,4,-1,2,1,-5,4 };
    std::pair<int, int> subarrayIndex;

    int sum = maxSubarraySum(arr, subarrayIndex);

    std::cout << "The longest subarray sum = " << sum << std::endl;

    std::cout << "The subarray indexes (start, stop) = " << subarrayIndex.first
        << "," << subarrayIndex.second << std::endl;

    return 0;
}
