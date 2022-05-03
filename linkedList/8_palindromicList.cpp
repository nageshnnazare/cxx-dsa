#include <iostream>

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode* next) : val(x), next(next) {};
};

ListNode* reverseList(ListNode* head) {
    if (head == nullptr) return nullptr;
    ListNode* newHead = nullptr;
    while (head) {
        ListNode* next = head->next;
        head->next = newHead;
        newHead = head;
        head = next;
    }
    return newHead;
}

bool palindromicList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return true;
    ListNode* fast = head;
    ListNode* slow = head;

    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = reverseList(slow->next);
    slow = slow->next;

    while (slow) {
        if (head->val != slow->val) {
            return false;
        }
        head = head->next;
        slow = slow->next;
    }
    return true;
}

int main(int argc, char const* argv[]) {
    ListNode node7(1);
    ListNode node6(2, &node7);
    ListNode node5(3, &node6);
    ListNode node4(4, &node5);
    ListNode node3(3, &node4);
    ListNode node2(2, &node3);
    ListNode node1(1, &node2);

    ListNode* head = &node1;

    {
        ListNode* temp = head;
        std::cout << "Original List : ";
        while (temp) {
            std::cout << temp->val << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    bool res = palindromicList(head);
    std::cout << "Result : " << std::boolalpha << res << std::endl;

    return 0;
}
