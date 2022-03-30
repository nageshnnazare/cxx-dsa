#include <iostream>
#include <vector>

int binarySearchOrderNotKnown(std::vector<int>& nums, int key) {
    int start = 0, end = nums.size() - 1;
    int asc = (nums[start] < nums[end]) ? 1 : 0;

    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] == key) {
            return mid;
        }
        if (nums[mid] > key) {
            end = asc ? mid - 1 : end;
            start = asc ? start : mid + 1;
        }
        else if (nums[mid] < key) {
            end = asc ? end : mid - 1;
            start = asc ? mid + 1 : start;
        }
    }

    return -1;
}

int main(int argc, char const* argv[]) {
    {
        std::vector<int> input = { 10,8,6,4,2,1 };
        int output = binarySearchOrderNotKnown(input, 2);

        {
            std::cout << "\nInput :\n";
            for (auto itr : input)
                std::cout << itr << "\t";
        }

        std::cout << "\nOutput :\n";
        std::cout << output;

    }

    {
        std::vector<int> input = { 1,2,4,5,6,10 };

        int output = binarySearchOrderNotKnown(input, 4);

        {
            std::cout << "\nInput :\n";
            for (auto itr : input)
                std::cout << itr << "\t";
        }

        std::cout << "\nOutput :\n";
        std::cout << output;

    }

    return 0;
}