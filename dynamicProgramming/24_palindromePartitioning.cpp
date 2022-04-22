#include <iostream>
#include <string>
#include <cstring>

int mem[100][100];

bool isPalindrome(std::string str, int i, int j) {
    if (i > j) {
        return false;
    }
    else if (i == j) {
        return true;
    }
    while (i <= j) {
        if (str[i] != str[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}


int palindromePartition(std::string str, int i, int j) {
    if (i >= j || isPalindrome(str, i, j)) {
        return 0;
    }

    if (mem[i][j] != -1) {
        return mem[i][j];
    }

    int ans = INT32_MAX;

    for (int k = i; k <= j - 1; k++) {
        int temp_left, temp_right;
        if (mem[i][k] != -1) {
            temp_left = mem[i][k];
        }
        else {
            mem[i][k] = temp_left = palindromePartition(str, i, k);
        }

        if (mem[k + 1][j] != -1) {
            temp_right = mem[k + 1][j];
        }
        else {
            mem[k + 1][j] = temp_right = palindromePartition(str, k + 1, j);
        }

        int temp = temp_left + temp_right + 1;
        ans = std::min(ans, temp);
    }
    return mem[i][j] = ans;
}

int main(int argc, char const* argv[]) {

    std::string str = "nitinab";

    std::cout << "\nInput : "
        << str << " ";

    memset(mem, -1, sizeof(mem));

    int output_td = palindromePartition(str, 0, str.length() - 1);

    std::cout << "\nOutput : "
        << output_td << std::endl;

    return 0;
}
