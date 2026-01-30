// Given two integers left and right, return a list of all the self-dividing numbers in the range [left, right] (both inclusive).




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int>ans;
        for(int i = left;i <= right;i ++){
            if(isSelfDividing(i)) ans.push_back(i);
        }
        return ans;
    }

    bool isSelfDividing(int num){
        for(int i = num;i > 0; i /= 10){
            if((i % 10 == 0) || (num % (i % 10) != 0)) return false;
        }
        return true;
    }
};

int main(){
    Solution sol;
    int left = 1, right = 22;
    vector<int> result = sol.selfDividingNumbers(left, right);
    cout<<"Self divinding numbers between "<<left<<" and "<<right<<" are : ";
    for(int num : result)cout << num << " ";
}