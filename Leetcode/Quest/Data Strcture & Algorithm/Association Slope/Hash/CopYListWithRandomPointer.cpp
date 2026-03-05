// A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null. Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list. Return the head of the copied linked list.





#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* dummy = new Node(0);
        Node* tail = dummy;
        unordered_map<Node*, Node*> d;
        for (Node* cur = head; cur; cur = cur->next) {
            Node* node = new Node(cur->val);
            tail->next = node;
            tail = node;
            d[cur] = node;
        }
        for (Node* cur = head; cur; cur = cur->next) {
            d[cur]->random = cur->random ? d[cur->random] : nullptr;
        }
        return dummy->next;
    }
};

void print(Node* head) {
    Node* cur = head;
    while (cur) {
        cout << "Node value: " << cur->val;
        if (cur->random) cout << ", Random points to: " << cur->random->val;
        else cout << ", Random points to: null";
        cout << endl;
        cur = cur->next;
    }
}

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->random = head->next;
    head->next->random = head->next;
    cout<<"Original List : ";
    print(head);
    Solution sol;
    Node* copiedHead = sol.copyRandomList(head);
    cout<<"Copied List : ";
    print(copiedHead);
}