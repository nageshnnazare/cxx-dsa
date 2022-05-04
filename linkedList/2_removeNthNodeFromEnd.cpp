#include <iostream>

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode* next) : val(x), next(next) {};
};


ListNode* removeNthNodeFromEnd(ListNode* head, int n) {
    if (head == nullptr) return nullptr;
    ListNode* fast = head;
    ListNode* slow = head;

    ListNode* start = new ListNode();
    start->next = head;

    int count = 0;
    while (count < n) {
        fast = fast->next;
        count++;
    }
    if (fast == nullptr) {
        return head->next;
    }
    while (fast->next) {
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = slow->next->next;

    return start->next;
}

int main(int argc, char const* argv[]) {

    ListNode node4(4);
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

    ListNode* res = removeNthNodeFromEnd(head, 3);
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
