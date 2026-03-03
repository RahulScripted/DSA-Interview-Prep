// Given the head of a singly linked list, reverse the list, and return the reversed list.



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
    ListNode* reverseList(ListNode* head) {
        ListNode* node = nullptr;
        while(head){
            ListNode* temp = head -> next;
            head -> next = node;
            node = head;
            head = temp;
        }
        return node;
    }
};

void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    ListNode* head = new ListNode(1);
    head -> next = new ListNode(2);
    head -> next -> next = new ListNode(3);
    head -> next -> next -> next = new ListNode(4);
    head -> next -> next -> next -> next = new ListNode(5);
    cout << "Original Linked List: ";
    printList(head);

    Solution sol;
    ListNode* reversedHead = sol.reverseList(head);
    cout << "Reversed Linked List: ";
    printList(reversedHead);
}