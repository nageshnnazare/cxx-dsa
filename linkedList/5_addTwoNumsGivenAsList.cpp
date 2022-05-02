#include <iostream>

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode* next) : val(x), next(next) {};
};


ListNode* addNumsGivenAsList(ListNode* head1, ListNode* head2) {
    ListNode* res = new ListNode();
    ListNode* temp = res;
    int carry = 0;
    while (head1 || head2 || carry) {
        int sum = 0;
        if (head1) {
            sum += head1->val;
            head1 = head1->next;
        }
        if (head2) {
            sum += head2->val;
            head2 = head2->next;
        }
        sum += carry;
        carry = sum / 10;
        ListNode* node = new ListNode(sum % 10);
        temp->next = node;
        temp = temp->next;
    }
    return res->next;
}

int main(int argc, char const* argv[]) {
    ListNode node3_1(5);
    ListNode node2_1(9, &node3_1);
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

    ListNode* res = addNumsGivenAsList(head_1, head_2);
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
