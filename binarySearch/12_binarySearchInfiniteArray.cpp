#include <iostream>
#include <vector>

int bsInfinite(std::vector<int>& nums, int key) {
    int res = -1;
    int start = 0, end = 1;
    while (key > nums[end]) {
        start = end;
        end = 2 * end;
    }

    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] == key) {
            return mid;
        }
        if (nums[mid] > key) {
            end = mid - 1;
        }
        else if (nums[mid] < key) {
            start = mid + 1;
        }
    }

    return res;
}


int main(int argc, char const* argv[]) {
    std::vector<int> input = { 1,2,3,4,5,7,8,9,10,11,12,23,44,55,66,77,88,99,100,132,344,345,678 };
    int output = bsInfinite(input, 77);

    {
        std::cout << "\nInput :\n";
        for (auto itr : input)
            std::cout << itr << "\t";
    }

    std::cout << "\nOutput :\n";
    std::cout << output << "\n";
    return 0;
}
