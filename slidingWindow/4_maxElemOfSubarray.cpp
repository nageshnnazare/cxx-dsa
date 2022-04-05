#include <iostream>
#include <vector>
#include <list>

std::vector<int> maxOfSubarray(std::vector<int> nums, int k) {
    int i = 0, j = 0;
    std::list<int> l;
    std::vector<int> res;

    while (j < nums.size()) {
        while (l.size() > 0 && l.back() < nums[j]) {
            l.pop_back();
        }
        l.push_back(nums[j]);

        if (j - i + 1 < k) {
            j++;
        }
        else if (j - i + 1 == k) {
            res.push_back(l.front());
            if (nums[i] == l.front()) {
                l.pop_front();
            }
            i++; j++;
        }
    }
    return res;
}


int main(int argc, char const* argv[]) {
    std::vector<int> input = { 12,-1,-7,8,-16,30,16,28 };
    std::vector<int> output;

    {
        std::cout << "\nInput :\n";
        for (auto itr : input)
            std::cout << itr << "\t";
    }

    output = maxOfSubarray(input, 3);

    {
        std::cout << "\nOutput :\n";
        for (auto itr : output)
            std::cout << itr << "\t";
    }

    return 0;
}
