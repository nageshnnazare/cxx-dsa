#include <iostream>
#include <vector>

char nextAlphabeticalElement(std::vector<char>& alphabet, char elem) {
    int start = 0, end = alphabet.size() - 1;
    char res = '#';

    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (alphabet[mid] <= elem) {
            start = mid + 1;
        }
        else if (alphabet[mid] > elem) {
            res = alphabet[mid];
            end = mid - 1;
        }
    }
    return res;
}

int main(int argc, char const* argv[]) {
    std::vector<char> input = { 'a', 'b', 'c', 'f', 'h' };
    char output = nextAlphabeticalElement(input, 'b');

    {
        std::cout << "\nInput :\n";
        for (auto itr : input)
            std::cout << itr << "\t";
    }

    std::cout << "\nOutput :\n";
    std::cout << output << "\n";

    return 0;
}
