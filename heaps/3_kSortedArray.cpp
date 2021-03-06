#include <iostream>
#include <vector>
#include <queue>

std::vector<int> kthSort(std::vector<int>& nums, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    std::vector<int> res;
    for (int i = 0;i < nums.size(); i++) {
        minHeap.push(nums[i]);
        if (minHeap.size() > k) {
            res.push_back(minHeap.top());
            minHeap.pop();
        }
    }
    for (int i = 0; i < k; i++) {
        res.push_back(minHeap.top());
        minHeap.pop();
    }

    return res;
}


int main(int argc, char const* argv[]) {
    std::vector<int> input = { 6,5,3,2,8,10,9 };

    std::vector<int> output = kthSort(input, 3);

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