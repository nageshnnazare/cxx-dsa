#include <iostream>
#include <vector>

void insert(std::vector<int>& nums, int num) {
    if (nums.size() == 0 || nums[nums.size() - 1] <= num) {
        nums.push_back(num);
        return;
    }
    int temp = nums[nums.size() - 1];
    nums.pop_back();
    insert(nums, num);

    nums.push_back(temp);
    return;
}

void sort(std::vector<int>& nums) {
    if (nums.size() == 1) {
        return;
    }
    int temp = nums[nums.size() - 1];
    nums.pop_back();
    sort(nums);

    insert(nums, temp);
    return;
}


int main(int argc, char const* argv[]) {
    std::vector<int> arr = { 1,2,4,7,2,6,8 };

    {
        std::cout << "\nInput :\n";
        for (auto itr : arr)
            std::cout << itr << "\t";
    }

    sort(arr);

    {
        std::cout << "\nOutput :\n";
        for (auto itr : arr)
            std::cout << itr << "\t";
    }

    return 0;
}
