#include <iostream>
#include <vector>
#include <queue>

std::vector<int> kLargest(std::vector<int>& nums, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    std::vector<int> res;

    for (int i = 0; i < nums.size(); i++) {
        minHeap.push(nums[i]);
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    while (minHeap.size() > 0) {
        res.push_back(minHeap.top());
        minHeap.pop();
    }

    return res;
}


int main(int argc, char const* argv[]) {
    std::vector<int> input = { 7, 10, 4, 3, 15, 20 };

    std::vector<int> output = kLargest(input, 4);

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
