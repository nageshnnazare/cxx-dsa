#include <iostream>
#include <string>
#include <unordered_map>

int pickToys(std::string str, int k) {
    int i = 0, j = 0;
    std::unordered_map<char, int> mp;
    int maxlen = 0;

    while (j < str.length()) {
        mp[str[j]]++;

        if (mp.size() < k) {
            j++;
        }
        else if (mp.size() == k) {
            maxlen = std::max(maxlen, j - i + 1);
            j++;
        }
        else {
            while (mp.size() > k) {
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
    std::string input = "abaccab";
    int output;

    {
        std::cout << "\nInput :\n";
        std::cout << input;
    }

    output = pickToys(input, 2);

    {
        std::cout << "\nOutput :\n";
        std::cout << output << "\n";
    }

    return 0;
}