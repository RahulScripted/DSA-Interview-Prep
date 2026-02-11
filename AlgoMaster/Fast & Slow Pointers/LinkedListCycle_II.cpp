// Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null. There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter. Do not modify the linked list.





#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }

        if (!(fast && fast->next)) return NULL;

        while (head != slow) {
            head = head->next;
            slow = slow->next;
        }

        return head;
    }
};

ListNode* createCycleList() {
    ListNode* n1 = new ListNode(3);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(0);
    ListNode* n4 = new ListNode(-4);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n2;
    return n1;
}

int main() {
    Solution sol;

    ListNode* head = createCycleList();
    ListNode* cycleStart = sol.detectCycle(head);

    if (cycleStart) cout << "Cycle detected at node with value: " << cycleStart->val << endl;
    else cout << "No cycle detected." << endl;
}
