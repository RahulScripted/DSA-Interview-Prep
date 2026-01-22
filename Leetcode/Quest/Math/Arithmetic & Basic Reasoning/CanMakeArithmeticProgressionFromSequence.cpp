// A sequence of numbers is called an arithmetic progression if the difference between any two consecutive elements is the same. Given an array of numbers arr, return true if the array can be rearranged to form an arithmetic progression. Otherwise, return false.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int diff = arr[1] - arr[0], n = arr.size(); 
        for(int i = 2; i < n ;i++){
            if((arr[i] - arr[i - 1]) != diff) return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {3,5,1};
    bool result = sol.canMakeArithmeticProgression(arr);
    cout<<"Can form Arithmetic Progression: " << (result ? "True" : "False") << endl;

    arr = {1,2,4};
    result = sol.canMakeArithmeticProgression(arr);
    cout<<"Can form Arithmetic Progression: " << (result ? "True" : "False") << endl;
    return 0;
}