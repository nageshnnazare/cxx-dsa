#include <iostream>
#include <string>
#include <unordered_map>

int countOccurrancesOfAnagram(std::string str, std::string anagram) {
    std::unordered_map<char, int> mp;  // character : count
    for (auto i : anagram) {
        mp[i]++;
    }

    int count = mp.size(), maxCount = 0;
    int i = 0, j = 0;

    while (j < str.length()) {
        if (mp.find(str[j]) != mp.end()) {
            mp[str[j]]--;
        }
        if (mp[str[j]] == 0) {
            count--;
        }

        if (j - i + 1 < anagram.length()) {
            j++;
        }
        else if (j - i + 1 == anagram.length()) {
            if (count == 0) {
                maxCount++;
            }
            if (mp.find(str[i]) != mp.end()) {
                mp[str[i]]++;
            }
            if (mp[str[i]] == 1) {
                count++;
            }
            i++; j++;
        }
    }
    return maxCount;
}

int main(int argc, char const* argv[]) {
    std::string input = "rfoaxxorfxaofr";
    int output = 0;

    {
        std::cout << "\nInput :\n";
        std::cout << input;
    }

    output = countOccurrancesOfAnagram(input, "for");

    {
        std::cout << "\nOutput :\n";
        std::cout << output;
    }

    return 0;
}
