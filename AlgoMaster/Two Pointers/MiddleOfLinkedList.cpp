// Given the head of a singly linked list, return the middle node of the linked list. If there are two middle nodes, return the second middle node.




#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast -> next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        return slow;
    }
};

int main(){
    Solution s;
    ListNode* head = new ListNode(1);
    head -> next = new ListNode(2);
    head -> next -> next = new ListNode(3);
    head -> next -> next -> next = new ListNode(4);
    head -> next -> next -> next -> next = new ListNode(5);

    ListNode* middle = s.middleNode(head);
    cout << "Middle Node Value : " << middle -> val << endl;

    return 0;
}