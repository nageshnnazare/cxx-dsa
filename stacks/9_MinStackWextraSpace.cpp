#include <iostream>
#include <stack>
#include <vector>

std::stack<int> st;     // main stack
std::stack<int> sst;    // supporting stack

void push(int a) {
    st.push(a);
    if (sst.size() == 0 || sst.top() >= a)
        sst.push(a);
    return;
}

int pop() {
    if (st.size() == 0)
        return -1;
    int ret = st.top();
    if (st.top() == sst.top()) {
        sst.pop();
    }
    st.pop();
    return ret;
}

int getMin() {
    if (sst.size() == 0)
        return -1;
    return sst.top();
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
