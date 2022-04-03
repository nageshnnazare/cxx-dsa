#include <iostream>
#include <stack>

void insert(std::stack<int>& st, int num) {
    if (st.size() == 0) {
        st.push(num);
        return;
    }
    int temp = st.top();
    st.pop();

    insert(st, num);
    st.push(temp);
    return;
}

void st_reverse(std::stack<int>& st) {
    if (st.size() == 1) {
        return;
    }

    int temp = st.top();
    st.pop();

    st_reverse(st);

    insert(st, temp);

    return;
}

int main(int argc, char const* argv[]) {
    std::stack <int> st;
    for (int i = 0; i < 10; i++) {
        st.push(i);
    }

    {
        int n = st.size();
        std::stack<int> p_st = st;

        std::cout << "\nInput :\n";
        for (int i = 0; i < n; i++) {
            std::cout << p_st.top() << "\t";
            p_st.pop();
        }
    }

    st_reverse(st);

    {
        int n = st.size();
        std::stack<int> p_st = st;

        std::cout << "\nOutput :\n";
        for (int i = 0; i < n; i++) {
            std::cout << p_st.top() << "\t";
            p_st.pop();
        }
    }

    return 0;
}