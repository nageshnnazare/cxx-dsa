#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

std::vector<int> nsl(std::vector<int> nums) {
    std::vector<int> leftres;
    std::stack<std::pair<int, int>> st;
    int pseudo_index = -1;
    for (int i = 0; i < nums.size(); i++) {
        if (st.size() == 0) {
            leftres.push_back(pseudo_index);
        }
        else if (st.size() > 0 && st.top().first < nums[i]) {
            leftres.push_back(st.top().second);
        }
        else if (st.size() > 0 && st.top().first >= nums[i]) {
            while (st.size() > 0 && st.top().first >= nums[i]) {
                st.pop();
            }
            if (st.size() == 0) {
                leftres.push_back(-1);
            }
            else {
                leftres.push_back(st.top().second);
            }
        }
        st.push(std::make_pair(nums[i], i));
    }

    return leftres;
}

std::vector<int> nsr(std::vector<int> nums) {
    std::vector<int> rightres;
    std::stack<std::pair<int, int>> st;
    int pseudo_index = nums.size();
    for (int i = nums.size() - 1; i >= 0; i--) {
        if (st.size() == 0) {
            rightres.push_back(pseudo_index);
        }
        else if (st.size() > 0 && st.top().first < nums[i]) {
            rightres.push_back(st.top().second);
        }
        else if (st.size() > 0 && st.top().first >= nums[i]) {
            while (st.size() > 0 && st.top().first >= nums[i]) {
                st.pop();
            }
            if (st.size() == 0) {
                rightres.push_back(pseudo_index);
            }
            else {
                rightres.push_back(st.top().second);
            }
        }
        st.push(std::make_pair(nums[i], i));
    }

    std::reverse(rightres.begin(), rightres.end());

    return rightres;
}

int maxAreaHist(std::vector<int> nums) {
    std::vector<int> left = nsl(nums);
    std::vector<int> right = nsr(nums);

    std::vector<int> area;
    for (int i = 0; i < nums.size(); i++) {
        area.push_back((nums[i]) * (right[i] - left[i] - 1));
    }

    int maxArea = *std::max_element(area.begin(), area.end());

    return maxArea;
}

int maxAreaBinMat(std::vector<std::vector<int>> input) {
    std::vector<std::vector<int>> h;
    std::vector<int> mah;
    h.push_back(input[0]);

    for (int i = 1; i < input.size(); i++) {
        std::vector<int> v;
        for (int j = 0; j < input[i].size(); j++) {
            int e = input[i][j] + h[i - 1][j];
            if (input[i][j] == 0) {
                e = 0;
            }
            v.push_back(e);
        }
        h.push_back(v);
        mah.push_back(maxAreaHist(v));
    }

    int maxArea = *std::max_element(mah.begin(), mah.end());

    return maxArea;
}


int main(int argc, char const* argv[]) {
    std::vector<std::vector<int>> input = { {0,1,1,0}, {1,1,1,1}, {1,1,1,1}, {1,1,0,0} };

    std::cout << "\nInput :\n";
    for (int i = 0; i < input.size(); i++) {
        for (int j = 0; j < input[i].size(); j++) {
            std::cout << input[i][j] << "\t";
        }
        std::cout << "\n";
    }

    int output = maxAreaBinMat(input);

    std::cout << "\nOutput :\n" << output << "\n";
    return 0;
}
