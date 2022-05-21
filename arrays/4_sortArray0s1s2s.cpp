#include <iostream>
#include <vector>

void sortDigits(std::vector<int>& nums) {
    int lo = 0;
    int hi = nums.size() - 1;
    int mid = 0;

    while (mid <= hi) {
        switch (nums[mid]) {
        case 0:
            std::swap(nums[lo++], nums[mid++]);
            break;

        case 1:
            mid++;
            break;

        case 2:
            std::swap(nums[mid], nums[hi--]);
            break;
        }
    }
}

int main(int argc, char const* argv[]) {
    std::vector<int> arr = { 0,1,2,0,2,1,0,1,2,1 };
    {
        std::cout << "Input : ";
        for (auto& i : arr) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    sortDigits(arr);

    {
        std::cout << "Output : ";
        for (auto& i : arr) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }


    return 0;
}
