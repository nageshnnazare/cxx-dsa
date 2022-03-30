#include <iostream>
#include <vector>

std::pair<int, int> firstAndLastOccurrenceOfElements(std::vector<int>& nums, int key) {
    std::pair<int, int> ret;
    int firstOccr = -1;
    int lastOccr = -1;
    {
        int start = 0, end = nums.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == key) {
                firstOccr = mid;
                end = mid - 1;
            }
            if (nums[mid] > key) {
                end = mid - 1;
            }
            else if (nums[mid] < key) {
                start = mid + 1;
            }
        }
    }
    {
        int start = 0, end = nums.size() - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == key) {
                lastOccr = mid;
                start = mid + 1;
            }
            if (nums[mid] > key) {
                end = mid - 1;
            }
            else if (nums[mid] < key) {
                start = mid + 1;
            }
        }

    }
    return std::make_pair(firstOccr, lastOccr);
}

int main(int argc, char const* argv[]) {
    std::vector<int> input = { 2,4,10,10,10,18,20 };
    std::pair<int, int> output = firstAndLastOccurrenceOfElements(input, 10);

    {
        std::cout << "\nInput :\n";
        for (auto itr : input)
            std::cout << itr << "\t";
    }

    std::cout << "\nOutput [First] [Last]:\n";
    std::cout << output.first << " " << output.second << "\n";

    return 0;
}
