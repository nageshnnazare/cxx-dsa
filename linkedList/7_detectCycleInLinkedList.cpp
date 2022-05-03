#include <iostream>

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode* next) : val(x), next(next) {};
};


bool detectCycle(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return false;
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}

int main(int argc, char const* argv[]) {
    ListNode node6_1;
    ListNode node5_1(3, &node6_1);
    ListNode node4_1(2, &node5_1);
    ListNode node3_1(9, &node4_1);
    ListNode node2_1(9, &node3_1);
    ListNode node1_1(2, &node2_1);
    node6_1.val = 5;
    node6_1.next = &node2_1;

    ListNode* head = &node1_1;

    bool res = detectCycle(head);
    std::cout << "Result : " << std::boolalpha << res << std::endl;

    return 0;
}
