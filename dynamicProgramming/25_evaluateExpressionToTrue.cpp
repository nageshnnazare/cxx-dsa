#include <iostream>
#include <string>
#include <cstring>

int mem[100][100];

int numWayToEvalToTrue(std::string str, int i, int j, bool isTrue) {

    if (i >= j) {
        if (isTrue == true) {
            return str[i] == 'T';
        }
        else {
            return str[i] == 'F';
        }
    }

    int ans = 0;

    for (int k = i + 1; k <= j - 1; k=k + 2) {
        int leftTrue, rightTrue, leftFalse, rightFalse;
        leftTrue = numWayToEvalToTrue(str, i, k - 1, true);
        leftFalse = numWayToEvalToTrue(str, i, k - 1, false);
        rightTrue = numWayToEvalToTrue(str, k + 1, j, true);
        rightFalse = numWayToEvalToTrue(str, k + 1, j, false);

        if (str[k] == '&') {
            if (isTrue == true) {
                ans = ans + (leftTrue * rightTrue);
            }
            else {
                ans = ans + (leftFalse * rightTrue)
                    + (leftTrue * rightFalse)
                    + (leftFalse * rightFalse);
            }
        }
        else if (str[k] == '|') {
            if (isTrue == true) {
                ans = ans + (leftTrue * rightTrue)
                    + (leftTrue * rightFalse)
                    + (leftFalse * rightTrue);
            }
            else {
                ans = ans + (leftFalse * rightFalse);
            }
        }
        else if (str[k] == '^') {
            if (isTrue == true) {
                ans = ans + (leftTrue * rightFalse)
                    + (rightTrue * leftFalse);
            }
            else {
                ans = ans + (leftFalse * rightFalse)
                    + (leftTrue * rightTrue);
            }
        }
    }
    return ans;
}

int main(int argc, char const* argv[]) {

    std::string str = "T|F&T^F";

    std::cout << "\nInput : "
        << str << " ";

    memset(mem, -1, sizeof(mem));

    int output_td = numWayToEvalToTrue(str, 0, str.length() - 1, true);

    std::cout << "\nOutput : "
        << output_td << std::endl;

    return 0;
}