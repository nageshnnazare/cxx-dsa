#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

std::vector<std::vector<int>> kClosestPoints(std::vector<std::vector<int>>& nums, int k) {
    std::priority_queue <std::pair<int, std::pair<int, int>>> maxHeap;
    std::vector<std::vector<int>> res;

    for (int i = 0; i < nums.size(); i++) {
        maxHeap.push(std::make_pair((nums[i][0] * nums[i][0]) + (nums[i][1] * nums[i][1]),
            std::make_pair(nums[i][0], nums[i][1])));
        if (maxHeap.size() > k) {
            maxHeap.pop();
        }
    }

    while (maxHeap.size() > 0) {
        std::vector<int> temp;
        temp.push_back(maxHeap.top().second.first);
        temp.push_back(maxHeap.top().second.second);
        res.push_back(temp);
        maxHeap.pop();
    }

    return res;
}

int main(int argc, char const* argv[]) {
    std::vector<std::vector<int>> input = { {1,3} , {-2,2}, {5,8}, {0,1} };

    std::vector<std::vector<int>> output = kClosestPoints(input, 3);

    {
        std::cout << "\nInput :\n";
        for (int i = 0; i < input.size(); i++) {
            for (int j = 0; j < 2; j++) {
                std::cout << input[i][j] << "\t";
            }
            std::cout << "\n";
        }
    }
    {
        std::cout << "\nOutput :\n";
        for (int i = 0; i < output.size(); i++) {
            for (int j = 0; j < 2; j++) {
                std::cout << output[i][j] << "\t";
            }
            std::cout << "\n";
        }
    }

    return 0;
}
