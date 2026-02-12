// Given two binary strings a and b, return their sum as a binary string.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int aLength = a.size() - 1;
        int bLength = b.size() - 1;
        int carry = 0;
        string res = "";

        while(aLength >= 0 || bLength >= 0 || carry){
            if(aLength >= 0) carry += a[aLength--] - '0';
            if(bLength >= 0) carry += b[bLength--] - '0';
            res += carry % 2 + '0';
            carry /= 2;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

int main(){
    Solution sol;
    string a = "11";
    string b = "1";
    cout<<"After addition  "<<a<<" + "<<b<<" will became : "<<sol.addBinary(a,b)<<endl;
}