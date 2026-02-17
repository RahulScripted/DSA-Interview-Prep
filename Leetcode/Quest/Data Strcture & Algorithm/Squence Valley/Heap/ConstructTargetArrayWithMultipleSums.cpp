// You are given an array target of n integers. From a starting array arr consisting of n 1's, you may perform the following procedure :

//     1 - let x be the sum of all elements currently in your array.
//     2 - choose index i, such that 0 <= i < n and set the value of arr at index i to x.

// You may repeat this procedure as many times as needed. Return true if it is possible to construct the target array from arr, otherwise, return false.






#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> pq;
        long long s = 0;
        for (int i = 0; i < target.size(); i++) {
            s += target[i];
            pq.push(target[i]);
        }
        while (pq.top() != 1) {
            int mx = pq.top();
            pq.pop();
            long long t = s - mx;
            if (t < 1 || mx - t < 1) return false;

            int x = mx % t;
            if (x == 0) x = t;
            pq.push(x);
            s = s - mx + x;
        }
        return true;
    }
};

int main(){
    Solution sol;
    vector<int>target = {9, 3, 5};

    if(sol.isPossible(target)) cout<<"Yes Possible"<<endl;
    else cout<<"Not possible"<<endl;

    target = {1, 1, 1, 2};
    if(sol.isPossible(target)) cout<<"Yes Possible"<<endl;
    else cout<<"Not possible"<<endl;
}