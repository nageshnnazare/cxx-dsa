#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::vector<int> res;
    std::unordered_map<int, int> mp;

    for (int i = 0; i < nums.size(); ++i) {

        if (mp.find(target - nums[i]) != mp.end()) {

            res.emplace_back(i);
            res.emplace_back(mp[target - nums[i]]);
            return res;
        }

        mp[nums[i]] = i;
    }

    return res;
}

int main(int argc, char const* argv[]) {
    std::vector<int> arr = { 1,3,5,7,3,4,6,9 };
    {
        std::cout << "Array : " << std::endl;
        for (auto& i : arr) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    std::vector<int> res = twoSum(arr, 6);
    {
        std::cout << "Result : " << std::endl;
        for (auto& i : res) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
