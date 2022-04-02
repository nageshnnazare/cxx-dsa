#include <iostream>
#include <vector>

int floorOfElement(std::vector<int>& nums, int elem) {
    int start = 0, end = nums.size() - 1;
    int res = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] == elem) {
            return nums[mid];
        }
        if (nums[mid] < elem) {
            res = nums[mid];
            start = mid + 1;
        }
        else if (nums[mid] > elem) {
            end = mid - 1;
        }
    }
    return res;
}

int ceilOfElement(std::vector<int>& nums, int elem) {
    int start = 0, end = nums.size() - 1;
    int res = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] == elem) {
            return nums[mid];
        }
        if (nums[mid] < elem) {
            start = mid + 1;
        }
        else if (nums[mid] > elem) {
            res = nums[mid];
            end = mid - 1;
        }
    }
    return res;
}

int minDiff(std::vector<int> nums, int key) {
    int floor = floorOfElement(nums, key);
    int ceil = ceilOfElement(nums, key);

    if (abs(key - floor) > abs(ceil - key)) {
        return ceil;
    }
    else {
        return floor;
    }
}

int main(int argc, char const* argv[]) {
    std::vector<int> input = { 2,5,6,8,11,12,15,18,20 };
    int output = minDiff(input, 13);

    {
        std::cout << "\nInput :\n";
        for (auto itr : input)
            std::cout << itr << "\t";
    }

    std::cout << "\nOutput :\n";
    std::cout << output << "\n";

    return 0;
}
