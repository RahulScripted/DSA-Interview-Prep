// You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation. Evaluate the expression. Return an integer that represents the value of the expression.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (auto& t : tokens) {
            if (t.size() > 1 || isdigit(t[0])) stk.push(stoi(t));
            else {
                int y = stk.top();
                stk.pop();
                int x = stk.top();
                stk.pop();
                if (t[0] == '+') stk.push(x + y);
                else if (t[0] == '-') stk.push(x - y);
                else if (t[0] == '*') stk.push(x * y);
                else stk.push(x / y);
            }
        }
        return stk.top();
    }
};

int main() {
    Solution sol;
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    cout << "Solution will be : " << sol.evalRPN(tokens) << endl;

    tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout << "Solution will be : " << sol.evalRPN(tokens) << endl;
}