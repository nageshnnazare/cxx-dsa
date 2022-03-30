#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

std::vector<int> kFreqNum(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> dict; // num : freq
    std::priority_queue<std::pair<int, int>,
        std::vector<std::pair<int, int>>,
        std::greater<std::pair<int, int>>> minHeap;

    std::vector<int> res;

    for (int i = 0; i < nums.size(); i++) {
        dict[nums[i]]++;
    }
    for (auto i = dict.begin(); i != dict.end(); i++) {
        minHeap.push(std::make_pair(i->second, i->first));
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }

    while (minHeap.size() > 0) {
        res.push_back(minHeap.top().second);
        minHeap.pop();
    }

    return res;
}

int main(int argc, char const* argv[]) {
    std::vector<int> input = { 1,1,1,2,3,2,4,4 };

    std::vector<int> output = kFreqNum(input, 3);

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