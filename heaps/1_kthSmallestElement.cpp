#include <iostream>
#include <vector>
#include <queue>

int kthSmallest(std::vector<int>& nums, int k) {
    std::priority_queue<int> maxHeap;
    for (int i = 0; i < nums.size(); i++) {
        maxHeap.push(nums[i]);
        if (maxHeap.size() > k) {
            maxHeap.pop();
        }
    }

    return maxHeap.top();
}


int main(int argc, char const* argv[]) {
    std::vector<int> input = { 1, 4, 2, 7, 3 };

    int output = kthSmallest(input, 5);

    {
        std::cout << "\nInput :\n";
        for (auto itr : input)
            std::cout << itr << "\t";
    }

    std::cout << "\nOutput :\n";
    std::cout << output;

    return 0;
}
