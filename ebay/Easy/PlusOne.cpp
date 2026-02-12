// You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's. Increment the large integer by one and return the resulting array of digits.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size() - 1;
        for(int i = n;i >= 0; i--){
            if(digits[i] + 1 != 10){
                digits[i] += 1;
                return digits;
            }
            digits[i] = 0;
            if(i == 0){
                digits.insert(digits.begin(), 1);
                return digits;
            }
        }
        return digits;
    }
};

void print(vector<int>& digits){
    for(auto it : digits)cout<<it<<" ";
    cout<<endl;
}

int main(){
    Solution sol;
    vector<int>digits = {1, 2, 3};
    cout<<"Before adding one : ";
    print(digits);

    vector<int>res = sol.plusOne(digits);
    cout<<"After adding one : ";
    print(digits);


    digits = {9};
    cout<<"Before adding one : ";
    print(digits);

    res = sol.plusOne(digits);
    cout<<"After adding one : ";
    print(digits);
}