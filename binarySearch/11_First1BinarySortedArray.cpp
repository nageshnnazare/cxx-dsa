#include <iostream>
#include <vector>

int searchFirst1(std::vector<int>& nums) {
    int res = -1;
    int start = 0, end = 1;
    while (1 > nums[end]) {
        start = end;
        end = 2 * end;
    }

    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] == 1) {
            res = mid;
            end = mid - 1;
        }
        else if (nums[mid] < 1) {
            start = mid + 1;
        }
    }
    return res;
}

int main(int argc, char const* argv[]) {
    std::vector<int> input = { 0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1 };
    int output = searchFirst1(input);

    {
        std::cout << "\nInput :\n";
        for (auto itr : input)
            std::cout << itr << "\t";
    }

    std::cout << "\nOutput :\n";
    std::cout << output << "\n";
    return 0;
}

