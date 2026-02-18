// Given two integers a and b, return the sum of the two integers without using the operators + and -.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        while(b != 0) {
            int carry = (a & b) << 1; 
            a = a ^ b;               
            b = carry;               
        }
        return a;
    }
};

int main(){
    Solution sol;
    int a = 2, b = 3;
    cout<<"Addition of "<<a<<" and "<<b<<" will be : "<<sol.getSum(a,b);
}