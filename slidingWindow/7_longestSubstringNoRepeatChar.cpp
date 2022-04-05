#include <iostream>
#include <string>
#include <unordered_map>

int longestSubstringNoRepeat(std::string str) {
    int i = 0, j = 0;
    std::unordered_map<char, int> mp;
    int maxlen = 0;

    while (j < str.length()) {
        mp[str[j]]++;

        if (mp.size() == j - i + 1) {
            maxlen = std::max(maxlen, j - i + 1);
            j++;
        }
        else if (mp.size() < j - i + 1) {
            while (mp.size() < j - i + 1) {
                mp[str[i]]--;
                if (mp[str[i]] == 0) {
                    mp.erase(str[i]);
                }
                i++;
            }
            j++;
        }
    }
    return maxlen;
}

int main(int argc, char const* argv[]) {
    std::string input = "pwwkew";
    int output;

    {
        std::cout << "\nInput :\n";
        std::cout << input;
    }

    output = longestSubstringNoRepeat(input);

    {
        std::cout << "\nOutput :\n";
        std::cout << output << "\n";
    }

    return 0;
}
