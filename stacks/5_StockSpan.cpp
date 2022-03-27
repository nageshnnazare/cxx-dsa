#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

std::vector<int> stockSpan(std::vector<int>& nums) {
    std::vector<int> res;
    std::stack<std::pair<int, int>> st;
    for (int i = 0; i < nums.size(); i++) {
        if (st.size() == 0) {
            res.push_back(-1);
        }
        else if (st.size() > 0 && st.top().first > nums[i]) {
            res.push_back(st.top().second);
        }
        else if (st.size() > 0 && st.top().first <= nums[i]) {
            while (st.size() > 0 && st.top().first <= nums[i]) {
                st.pop();
            }
            if (st.size() == 0) {
                res.push_back(-1);
            }
            else {
                res.push_back(st.top().second);
            }
        }
        st.push(std::make_pair(nums[i], i));
    }

    for (int i = 0; i < res.size(); i++) {
        res[i] = i - res[i];
    }

    return res;
}

int main(int argc, char const* argv[]) {
    std::vector<int> input = { 100,80,60,70,60,75,85 };

    std::vector<int> output = stockSpan(input);

    {
        std::cout << "\nInput :\n";
        for (auto itr : input)
            std::cout << itr << "\t";
    }

    {
        std::cout << "\nOutput :\n";
        for (auto itr : output)
            std::cout << itr << "\t";
    }

    return 0;
}
