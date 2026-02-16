// Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.




#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* lista = headA;
        ListNode* listb = headB;

        while (lista != listb) {
            lista = (lista != nullptr) ? lista->next : headB;
            listb = (listb != nullptr) ? listb->next : headA;
        }

        return lista;  
    }
};

void print(ListNode* head){
    while(head != nullptr){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    Solution sol;
    
    ListNode* intersection = new ListNode(8);
    intersection->next = new ListNode(4);
    intersection->next->next = new ListNode(5);
    
    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = intersection;
    
    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = intersection;
    
    ListNode* result = sol.getIntersectionNode(headA, headB);
    cout<<""
}