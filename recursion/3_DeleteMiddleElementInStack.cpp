#include <iostream>
#include <stack>

void solve(std::stack<int>& st, int k) {
    if (k == 1) {
        st.pop();
        return;
    }
    int temp = st.top();
    st.pop();
    solve(st, k - 1);

    st.push(temp);
    return;
}


std::stack<int> middleDelete(std::stack<int> st) {
    if (st.size() == 0) {
        return st;
    }
    int k = (st.size() / 2) + 1;
    solve(st, k);

    return st;
}


int main(int argc, char const* argv[]) {
    std::stack <int> input;
    input.push(5);
    input.push(1);
    input.push(4);
    input.push(7);
    input.push(3);
    input.push(9);
    input.push(2);
    input.push(3);

    {
        int n = input.size();
        std::stack<int> p_st = input;

        std::cout << "\nInput :\n";
        for (int i = 0; i < n; i++) {
            std::cout << p_st.top() << "\t";
            p_st.pop();
        }
    }

    std::stack<int> output = middleDelete(input);

    {
        int n = output.size();
        std::stack<int> p_st = output;

        std::cout << "\nOutput :\n";
        for (int i = 0; i < n; i++) {
            std::cout << p_st.top() << "\t";
            p_st.pop();
        }
    }

    return 0;
}