// A binary watch has 4 LEDs on the top to represent the hours (0-11), and 6 LEDs on the bottom to represent the minutes (0-59). Each LED represents a zero or one, with the least significant bit on the right. Given an integer turnedOn which represents the number of LEDs that are currently on (ignoring the PM), return all possible times the watch could represent. You may return the answer in any order.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSetBits(int x) {
        int cnt = 0;
        while (x) {
            x &= (x - 1);
            cnt++;
        }
        return cnt;
    }
    
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;

        for (int h = 0; h < 12; h++) {
            for (int m = 0; m < 60; m++) {
                if (countSetBits(h) + countSetBits(m) == turnedOn) {
                    string time = to_string(h) + ":";
                    if (m < 10) time += "0";
                    time += to_string(m);
                    ans.push_back(time);
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<string> result = s.readBinaryWatch(1);

    cout<<"All possible time : ";
    for (string s : result) cout << s << " ";
    cout << endl;
}