#include <iostream>
#include <stack>
#include <vector>

std::stack<int> st;     // main stack
int minElement;

void push(int a) {
    if (st.size() == 0) {
        st.push(a);
        minElement = a;
    }
    else {
        if (a >= minElement) {
            st.push(a);
        }
        else if (a < minElement) {
            st.push(2 * a - minElement);
        }
    }
    return;
}

int pop() {
    if (st.size() == 0) {
        return -1;
    }
    else {
        int ret = st.top();
        if (st.top() >= minElement) {
            st.pop();
        }
        else if (st.top() < minElement) {
            minElement = 2 * minElement - st.top();
            st.pop();
        }
        return ret;
    }
}

int top() {
    if (st.size() == 0) {
        return -1;
    }
    else {
        if (st.top() >= minElement) {
            return st.top();
        }
        else if (st.top() < minElement) {
            return minElement;
        }
    }
    return -1;
}

int getMin() {
    if (st.size() == 0) {
        return -1;
    }
    return minElement;
}


int main(int argc, char const* argv[]) {
    push(18); push(19); push(29);

    std::cout << getMin() << std::endl;

    push(15); push(16);
    std::cout << getMin() << std::endl;

    pop();
    std::cout << getMin() << std::endl;

    return 0;
}