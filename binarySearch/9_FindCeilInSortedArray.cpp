#include <iostream>
#include <vector>

int ceilOfElement(std::vector<int>& nums, int elem) {
    int start = 0, end = nums.size() - 1;
    int res = -1;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] == elem) {
            return mid;
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

int main(int argc, char const* argv[]) {
    std::vector<int> input = { 2,5,6,8,11,12,15,18,20 };
    int output = ceilOfElement(input, 13);

    {
        std::cout << "\nInput :\n";
        for (auto itr : input)
            std::cout << itr << "\t";
    }

    std::cout << "\nOutput :\n";
    std::cout << output << "\n";

    return 0;
}
