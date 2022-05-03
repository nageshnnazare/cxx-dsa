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

int main(int argc, char const* argv[]) {

    ListNode node3(3);
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

    ListNode* res = reverseList(head);
    {
        ListNode* temp = res;
        std::cout << "Solution List : ";
        while (temp) {
            std::cout << temp->val << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
    return 0;
}
