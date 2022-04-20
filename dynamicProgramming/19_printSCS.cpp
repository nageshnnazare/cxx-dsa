#include <iostream>
#include <string>
#include <algorithm>

std::string printSCS(std::string str1, std::string str2) {
    int n = str1.size();
    int m = str2.size();

    std::string result;

    int t[n + 1][m + 1];

    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < m + 1; j++) {
            if (i == 0 || j == 0) {
                t[i][j] = 0;
            }
        }
    }

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                t[i][j] = 1 + t[i - 1][j - 1];
            }
            else {
                t[i][j] = std::max(t[i][j - 1], t[i - 1][j]);
            }
        }
    }

    int i = n, j = m;
    while (i > 0 || j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            result.push_back(str1[i - 1]);
            i--; j--;
        }
        else {
            if (t[i][j - 1] > t[i - 1][j]) {
                result.push_back(str2[j - 1]);
                j--;
            }
            else {
                result.push_back(str1[i - 1]);
                i--;
            }
        }
    }

    while (i > 0) {
        result.push_back(str1[i - 1]);
        i--;
    }

    while (j > 0) {
        result.push_back(str2[j - 1]);
        j--;
    }

    std::reverse(result.begin(), result.end());

    return result;
}

int main(int argc, char const* argv[]) {
    std::string str1("acbcf");
    std::string str2("abcdaf");

    std::cout << "\nInput : "
        << str1 << " " << str2;

    std::string output_td = printSCS(str1, str2);

    std::cout << "\nOutput : "
        << "\nTop Down " << output_td << std::endl;

    return 0;
}

