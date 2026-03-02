// Given an array of unique integer numbers, count pairs (i, j) with i ≤ j such that numbers[i] + numbers[j] equals a power of two (1, 2, 4, 8, ...).





#include <bits/stdc++.h>
using namespace std;

int countPairs(vector<int>& numbers) {
    int count = 0;
    unordered_set<int> seen;
    
    for (int num : numbers) {
        for (int power = 1; power <= 2 * num; power <<= 1) {
            int complement = power - num;
            if (seen.count(complement)) count++;
        }
        seen.insert(num);
    }
    
    return count;
}

int main() {
    vector<int> numbers = {1, 3, 5, 7, 9};
    cout << "Number of pairs: " << countPairs(numbers) << endl;
    return 0;
}