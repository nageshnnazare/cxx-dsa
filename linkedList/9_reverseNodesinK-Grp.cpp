#include <iostream>

struct ListNode {
    int val;
    ListNode* next;

    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode* next) : val(x), next(next) {};
};

ListNode* reverseNodesK(ListNode* head, int k) {
    if (head == nullptr || k == 1) return head;
    ListNode* temp = new ListNode();
    temp->next = head;

    ListNode* curr = temp, * pre = temp, * nex = temp;
    int count = 0;

    while (curr->next) {
        curr = curr->next;
        count++;
    }

    while (count >= k) {
        curr = pre->next;
        nex = curr->next;

        for (int i = 1; i < k; i++) {
            curr->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = curr->next;
        }
        pre = curr;
        count -= k;
    }
    return temp->next;
}

int main(int argc, char const* argv[]) {
    ListNode node7(7);
    ListNode node6(6, &node7);
    ListNode node5(5, &node6);
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

    ListNode* res = reverseNodesK(head, 3);

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
