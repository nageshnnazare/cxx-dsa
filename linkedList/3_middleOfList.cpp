#include <iostream>

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode* next) : val(x), next(next) {};
};


ListNode* middleOfList(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;

    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

int main(int argc, char const* argv[]) {
    ListNode node5(5);
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

    ListNode* res = middleOfList(head);
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
