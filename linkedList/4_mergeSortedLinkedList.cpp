#include <iostream>

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode* next) : val(x), next(next) {};
};


ListNode* mergeSortedList(ListNode* head1, ListNode* head2) {
    if (head1 == nullptr) return head2;
    if (head2 == nullptr) return head1;

    if (head1->val > head2->val) {
        std::swap(head1, head2);
    }

    ListNode* result = head1;

    while (head1 && head2) {
        ListNode* temp = nullptr;
        while (head1 && head1->val <= head2->val) {
            temp = head1;
            head1 = head1->next;
        }
        temp->next = head2;

        std::swap(head1, head2);
    }
    return result;
}

int main(int argc, char const* argv[]) {
    ListNode node3_1(5);
    ListNode node2_1(4, &node3_1);
    ListNode node1_1(2, &node2_1);
    ListNode* head_1 = &node1_1;

    ListNode node2_2(3);
    ListNode node1_2(1, &node2_2);
    ListNode* head_2 = &node1_2;

    {
        ListNode* temp = head_1;
        std::cout << "Original List 1: ";
        while (temp) {
            std::cout << temp->val << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
    {
        ListNode* temp = head_2;
        std::cout << "Original List 2: ";
        while (temp) {
            std::cout << temp->val << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    ListNode* res = mergeSortedList(head_1, head_2);
    {
        ListNode* temp = res;
        std::cout << "Solution List  : ";
        while (temp) {
            std::cout << temp->val << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
    return 0;
}
