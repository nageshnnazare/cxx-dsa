#include <iostream>
#include <string>
#include <cstring>

int mem[100][100] = { 0 };

// Memoization
int longestCommonSubseq_mem(std::string str1, int n, std::string str2, int m) {
    if (n == 0 || m == 0) {
        return 0;
    }

    if (mem[n][m] != -1) {
        return mem[n][m];
    }

    if (str1[n - 1] == str2[m - 1]) {
        mem[n][m] = 1 + longestCommonSubseq_mem(str1, n - 1, str2, m - 1);
        return mem[n][m];
    }
    else {
        mem[n][m] = std::max(longestCommonSubseq_mem(str1, n, str2, m - 1),
            longestCommonSubseq_mem(str1, n - 1, str2, m));
        return mem[n][m];
    }
}

// Top down approach
int longestCommonSubseq_td(std::string str1, std::string str2) {
    int n = str1.size();
    int m = str2.size();

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
    return t[n][m];
}

int main(int argc, char const* argv[]) {
    std::string str1("abcdgh");
    std::string str2("abedfhr");

    std::cout << "\nInput : "
        << str1 << " " << str2;

    memset(mem, -1, sizeof(mem));

    int output_mem = longestCommonSubseq_mem(str1, str1.size(), str2, str2.size());

    int output_td = longestCommonSubseq_td(str1, str2);

    std::cout << "\nOutput : "
        << "\nMemoization " << output_mem << std::endl
        << "Top Down " << output_td << std::endl;


    return 0;
}
