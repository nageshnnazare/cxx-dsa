#include <iostream>
#include <vector>
#include <queue>

std::vector<int> kClosest(std::vector<int>& nums, int k, int x) {
    std::priority_queue<std::pair<int, int>> maxHeap; // diff : value
    std::vector<int> res;
    for (int i = 0; i < nums.size(); i++) {
        maxHeap.push(std::make_pair(abs(nums[i] - x), nums[i]));
        if (maxHeap.size() > k) {
            maxHeap.pop();
        }
    }

    while (maxHeap.size() > 0) {
        res.push_back(maxHeap.top().second);
        maxHeap.pop();
    }

    return res;
}

int main(int argc, char const* argv[]) {
    std::vector<int> input = { 6,5,3,2,8,10,9 };

    std::vector<int> output = kClosest(input, 3, 5);

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