#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

std::vector<int> kFreqNum(std::vector<int>& nums) {
    std::unordered_map<int, int> dict; // num : freq
    std::priority_queue <std::pair<int, int>> maxHeap;

    std::vector<int> res;

    for (int i = 0; i < nums.size(); i++) {
        dict[nums[i]]++;
    }
    for (auto i = dict.begin(); i != dict.end(); i++) {
        maxHeap.push(std::make_pair(i->second, i->first));
    }

    while (maxHeap.size() > 0) {
        int freq = maxHeap.top().first;
        int elem = maxHeap.top().second;

        for (int i = 1; i <= freq; i++) {
            res.push_back(maxHeap.top().second);
        }

        maxHeap.pop();
    }

    return res;
}

int main(int argc, char const* argv[]) {
    std::vector<int> input = { 1,1,0,2,3,2,4,4 };

    std::vector<int> output = kFreqNum(input);

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