// Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.




#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* res = head;

        while (head && head->next) {
            if (head->val == head->next->val) head->next = head->next->next;
            else head = head->next;
        }

        return res;   
    }
};

void print(ListNode* head){
    while(head){
        cout<<head -> val<<" ";
        head = head -> next;
    }
    cout<<endl;
}

int main(){
    Solution sol;
    ListNode* head = new ListNode(1, new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(3)))));
    cout<<"Before removing : ";
    print(head);

    ListNode* result = sol.deleteDuplicates(head);
    cout<<"After removing : ";
    print(result);
}