// You are given an integer array arr. Sort the integers in the array in ascending order by the number of 1's in their binary representation and in case of two or more integers have the same number of 1's you have to sort them in ascending order. Return the array after sorting it.





#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool compare(int a, int b) {
        int counta = __builtin_popcount(a);
        int countb = __builtin_popcount(b);
        if (counta == countb) return a < b;
        return counta < countb;
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
};

void print(const vector<int>& arr) {
    for (int num : arr) cout << num << " ";
    cout << endl;
}

int main() {
    Solution sol;
    vector<int> arr = {0,1,2,3,4,5,6,7,8};
    cout << "Original array: ";
    print(arr);
    vector<int> result = sol.sortByBits(arr);
    printf("Sorted array by number of 1's in binary representation: ");
    print(result);
}