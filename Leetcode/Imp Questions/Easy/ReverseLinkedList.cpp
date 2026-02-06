// Given the head of a singly linked list, reverse the list, and return the reversed list.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* node = nullptr;
        while(head){
            ListNode* temp = head -> next;
            head -> next =node;
            node = head;
            head = temp;
        }
        return node;
    }
};

int main(){
    Solution s;
    ListNode* head = new ListNode(1);
    head -> next = new ListNode(2);
    head -> next -> next = new ListNode(3);
    head -> next -> next -> next = new ListNode(4);
    head -> next -> next -> next -> next = new ListNode(5);

    ListNode* reversedHead = s.reverseList(head);
    cout<<"After reversing the linked list: ";
    while (reversedHead) {
        cout << reversedHead->val << " ";
        reversedHead = reversedHead->next;
    }
}