#include <iostream>
#include <string>
#include <cstring>

std::pair<int, int> minInsAndDeltoConvAtoB(std::string str1, std::string str2) {
    int n = str1.size();
    int m = str2.size();
    int numInsert = 0;
    int numDelete = 0;

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

    numDelete = n - maxlen;
    numInsert = m - maxlen;

    return std::make_pair(numInsert, numDelete);
}

int main(int argc, char const* argv[]) {
    std::string str1("heap");
    std::string str2("pea");

    std::cout << "\nInput : "
        << str1 << " " << str2;

    std::pair<int, int> output_td = minInsAndDeltoConvAtoB(str1, str2);

    std::cout << "\nOutput : "
        << "Insert = " << output_td.first << " "
        << "Delete = " << output_td.second
        << std::endl;

    return 0;
}
