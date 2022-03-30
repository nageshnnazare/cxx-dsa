#include <iostream>
#include <vector>

int rotatedCount(std::vector<int>& nums) {
    int n = nums.size() - 1, start = 0, end = n;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        int prev = (mid + n - 1) % n;
        int next = (mid + 1) % n;

        if (nums[mid] <= nums[next] && nums[mid] <= nums[prev])
            return mid;

        if (nums[start] < nums[mid])
            start = mid + 1;
        else if (nums[mid] < nums[end])
            end = mid - 1;

    }
    return -1;
}

int main(int argc, char const* argv[]) {
    std::vector<int> input = { 12,15,18,20,2,5,6,8,11 };
    int output = rotatedCount(input);

    {
        std::cout << "\nInput :\n";
        for (auto itr : input)
            std::cout << itr << "\t";
    }

    std::cout << "\nOutput :\n";
    std::cout << output << "\n";

    return 0;
}