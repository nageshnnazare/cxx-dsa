#include <iostream>
#include <string>

std::string reverseWordsInString(std::string s) {
    int left = 0;
    int right = s.length() - 1;

    std::string temp = "";
    std::string ans = "";

    while (left <= right) {
        char ch = s[left];
        if (ch != ' ') {
            temp += ch;
        }
        else if (ch == ' ') {
            if (ans != "") ans = temp + " " + ans;
            else ans = temp;
            temp = "";
        }
        left++;
    }

    if (temp != "") {
        if (ans != "") ans = temp + " " + ans;
        else ans = temp;
    }

    return ans;
}

int main(int argc, char const* argv[]) {
    std::string st = "this is a code for reversing a string";
    std::cout << "Before reversing words: " << std::endl;
    std::cout << st << std::endl;
    std::cout << "After reversing words: " << std::endl;
    std::cout << reverseWordsInString(st) << std::endl;
    return 0;
}

/*
Output:

Before reversing words:
this is a code for reversing a string
After reversing words:
string a reversing for code a is this

*/