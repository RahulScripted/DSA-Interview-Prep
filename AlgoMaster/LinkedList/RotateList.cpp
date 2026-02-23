// Given the head of a linked list, rotate the list to the right by k places.




#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        int length = 1;
        ListNode* dummy = head;

        while (dummy->next) {
            dummy = dummy->next;
            length++;
        }

        int position = k % length;
        if (position == 0) return head;

        ListNode* current = head;
        for (int i = 0; i < length - position - 1; ++i) current = current->next;
        ListNode* newHead = current->next;
        current->next = nullptr;
        dummy->next = head;

        return newHead;        
    }
};

void printList(ListNode* head) {
    ListNode* current = head;
    while (current) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Solution sol;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    cout<<"Original List: ";
    printList(head);

    int k = 2;
    ListNode* rotatedHead = sol.rotateRight(head, k);
    cout<<"Rotated List: ";
    printList(rotatedHead);
}