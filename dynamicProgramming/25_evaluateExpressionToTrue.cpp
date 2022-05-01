#include <iostream>
#include <string>
#include <cstring>
#include <unordered_map>

std::unordered_map<std::string, int> umap;

int numWayToEvalToTrue(std::string str, int i, int j, bool isTrue) {
    std::string key = std::to_string(i) + " "
        + std::to_string(j) + " "
        + (isTrue ? "T" : "F");

    if (umap.find(key) != umap.end()) {
        return umap[key];
    }

    if (i >= j) {
        if (isTrue == true) {
            umap[key] = str[i] == 'T';
        }
        else {
            umap[key] = str[i] == 'F';
        }
        return umap[key];
    }

    int ans = 0;

    for (int k = i + 1; k <= j - 1; k = k + 2) {
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
    return umap[key] = ans;
}

int main(int argc, char const* argv[]) {

    std::string str = "T|F&T^F";

    std::cout << "\nInput : "
        << str << " ";

    umap.clear();

    int output_td = numWayToEvalToTrue(str, 0, str.length() - 1, true);

    std::cout << "\nOutput : "
        << output_td << std::endl;

    return 0;
}