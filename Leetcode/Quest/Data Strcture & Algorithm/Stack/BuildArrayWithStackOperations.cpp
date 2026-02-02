// You are given an integer array target and an integer n. You have an empty stack with the two following operations:

//     1 - "Push": pushes an integer to the top of the stack.
//     2 - "Pop": removes the integer on the top of the stack.

// You also have a stream of the integers in the range [1, n]. Use the two stack operations to make the numbers in the stack (from the bottom to the top) equal to target. You should follow the following rules:

//     1 - If the stream of the integers is not empty, pick the next integer from the stream and push it to the top of the stack.
//     2 - If the stack is not empty, pop the integer at the top of the stack.
//     3 - If, at any moment, the elements in the stack (from the bottom to the top) are equal to target, do not read new integers from the stream and do not do more operations on the stack.

// Return the stack operations needed to build target following the mentioned rules. If there are multiple valid answers, return any of them.






#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>ans;
        int curr = 1;
        for(int num : target){
            while(curr < num){
                ans.push_back("Push");
                ans.push_back("Pop");
                ++curr;
            }
            ans.push_back("Push");
            ++curr;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> target = {1,3};
    int n = 3;
    vector<string> result = sol.buildArray(target, n);
    cout<<"Operations: ";
    for (const string& op : result) cout << op << " ";

    target = {1,2};
    n = 4;
    result = sol.buildArray(target, n);
    cout<<"Operations: ";
    for (const string& op : result) cout << op << " ";
}