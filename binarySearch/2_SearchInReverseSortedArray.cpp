#include <iostream>
#include <vector>

int binarySearchReverse(std::vector<int>& nums, int key) {
    int start = 0, end = nums.size() - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] == key) {
            return mid;
        }
        if (nums[mid] < key) {
            end = mid - 1;
        }
        else if (nums[mid] > key) {
            start = mid + 1;
        }
    }

    return -1;
}

int main(int argc, char const* argv[]) {
    std::vector<int> input = { 10,8,6,4,2,1 };

    int output = binarySearchReverse(input, 2);

    {
        std::cout << "\nInput :\n";
        for (auto itr : input)
            std::cout << itr << "\t";
    }

    std::cout << "\nOutput :\n";
    std::cout << output;

    return 0;
}
