#include <iostream>
#include <stack>

void insert(std::stack<int>& st, int num) {
    if (st.size() == 0 || st.top() <= num) {
        st.push(num);
        return;
    }
    int temp = st.top();
    st.pop();
    insert(st, num);

    st.push(temp);
    return;
}

void sort(std::stack<int>& st) {
    if (st.size() == 1) {
        return;
    }
    int temp = st.top();
    st.pop();
    sort(st);

    insert(st, temp);
    return;
}


int main(int argc, char const* argv[]) {
    std::stack <int> st;
    st.push(5);
    st.push(1);
    st.push(4);
    st.push(7);
    st.push(3);
    st.push(9);
    st.push(2);
    st.push(3);

    {
        int n = st.size();
        std::stack<int> p_st = st;

        std::cout << "\nInput :\n";
        for (int i = 0; i < n; i++) {
            std::cout << p_st.top() << "\t";
            p_st.pop();
        }
    }

    sort(st);

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
