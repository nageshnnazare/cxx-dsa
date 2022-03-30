#include <iostream>
#include <vector>

int binarySearch(std::vector<int>& nums, int key, int start, int end) {
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] == key) {
            return mid;
        }
        if (nums[mid] > key) {
            end = mid - 1;
        }
        else if (nums[mid] < key) {
            start = mid + 1;
        }
    }
    return -1;
}

int searchInSortedRotatedArray(std::vector<int>& nums, int key) {
    int n = nums.size() - 1, start = 0, end = n;
    int index = -1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        int prev = (mid + n - 1) % n;
        int next = (mid + 1) % n;

        if (nums[mid] <= nums[next] && nums[mid] <= nums[prev]) {
            index = mid;
            break;
        }

        if (nums[start] < nums[mid])
            start = mid + 1;
        else if (nums[mid] < nums[end])
            end = mid - 1;

    }
    if (index == -1)
        return -1;

    {
        int start = 0, end = index - 1;
        int res = binarySearch(nums, key, start, end);
        if (res != -1) {
            return res;
        }
    }

    {
        int start = index, end = n;
        int res = binarySearch(nums, key, start, end);
        if (res != -1) {
            return res;
        }
    }

    return -1;
}

int main(int argc, char const* argv[]) {
    std::vector<int> input = { 12,15,18,20,2,5,6,8,11 };
    int output = searchInSortedRotatedArray(input, 8);

    {
        std::cout << "\nInput :\n";
        for (auto itr : input)
            std::cout << itr << "\t";
    }

    std::cout << "\nOutput :\n";
    std::cout << output << "\n";

    return 0;
}