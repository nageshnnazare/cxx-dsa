#include <iostream>
#include <string>
#include <cstring>

int shortestCommonSuperSeq(std::string str1, std::string str2) {
    int n = str1.size();
    int m = str2.size();

    int t[n + 1][m + 1];
    int maxlen = 0;

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
                maxlen = std::max(maxlen, t[i][j]);
            }
            else {
                t[i][j] = std::max(t[i][j - 1], t[i - 1][j]);
            }
        }
    }

    return n + m - maxlen;
}

int main(int argc, char const* argv[]) {
    std::string str1("geek");
    std::string str2("eke");

    std::cout << "\nInput : "
        << str1 << " " << str2;

    int output_td = shortestCommonSuperSeq(str1, str2);

    std::cout << "\nOutput : "
        << "Top Down " << output_td << std::endl;

    return 0;
}
