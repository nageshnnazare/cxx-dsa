#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

std::vector<int> nsr(std::vector<int>& nums) {
    std::vector<int> res;
    std::stack<int> st;
    for (int i = nums.size() - 1; i >= 0; i--) {
        if (st.size() == 0) {
            res.push_back(-1);
        }
        else if (st.size() > 0 && st.top() < nums[i]) {
            res.push_back(st.top());
        }
        else if (st.size() > 0 && st.top() >= nums[i]) {
            while (st.size() > 0 && st.top() >= nums[i]) {
                st.pop();
            }
            if (st.size() == 0) {
                res.push_back(-1);
            }
            else {
                res.push_back(st.top());
            }
        }
        st.push(nums[i]);
    }

    std::reverse(res.begin(), res.end());

    return res;
}

int main(int argc, char const* argv[]) {
    std::vector<int> input = { 1, 4, 2, 7, 3 };

    std::vector<int> output = nsr(input);

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
