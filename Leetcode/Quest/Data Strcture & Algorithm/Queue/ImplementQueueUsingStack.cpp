// Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).




#include <bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    MyQueue() {
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        peek();
        const int val = output.top();
        output.pop();
        return val;
    }

    int peek() {
        if (output.empty()){
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }

    bool empty() {
        return input.empty() && output.empty();
    }

private:
    stack<int> input;
    stack<int> output;
};

int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    cout << "Peek element : " << q.peek() << endl;
    cout << "After pop out : " << q.pop() << endl;
    cout << "Is Empty? " << (q.empty() ? "Yes" : "No") << endl;
}