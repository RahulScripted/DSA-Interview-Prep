// Write a function that reverses a string. The input string is given as an array of characters s.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        // Two Pointer
        int left = 0, right = s.size() - 1;
        while(left < right){
            swap(s[left], s[right]);
            left++;
            right--;
        }

        // Built-in
        // reverse(s.begin(), s.end());
    }
};

void print(const vector<char>& s) {
    for (char ch : s) cout << ch << " ";
    cout << endl;
}

int main() {
    Solution sol;
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    cout << "Original string: ";
    print(s);

    sol.reverseString(s);
    cout << "Reversed string: ";
    print(s);
}