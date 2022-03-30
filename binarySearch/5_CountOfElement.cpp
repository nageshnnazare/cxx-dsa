#include <iostream>
#include <vector>

int countOfElement(std::vector<int>& nums, int key) {
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

    if (firstOccr > -1 && lastOccr > -1) {
        return lastOccr - firstOccr + 1;
    }
    return -1;
}

int main(int argc, char const* argv[]) {
    std::vector<int> input = { 2,4,10,10,10,18,20 };
    int output = countOfElement(input, 1);

    {
        std::cout << "\nInput :\n";
        for (auto itr : input)
            std::cout << itr << "\t";
    }

    std::cout << "\nOutput :\n";
    std::cout << output << "\n";

    return 0;
}
