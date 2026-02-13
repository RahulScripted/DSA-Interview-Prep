// You are given an array of integers stones where stones[i] is the weight of the ith stone. We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:

//     1 - If x == y, both stones are destroyed, and
//     2 - If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
//     3 - At the end of the game, there is at most one stone left.

// Return the weight of the last remaining stone. If there are no stones left, return 0.






#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq{stones.begin(), stones.end()};

        while (pq.size() >= 2) {
            const int n1 = pq.top();
            pq.pop();
            const int n2 = pq.top();
            pq.pop();
            if (n1 != n2) pq.push(n1 - n2);
        }

        return pq.empty() ? 0 : pq.top();
    }
};

int main(){
    Solution s;
    vector<int> v = {2,7,4,1,8,1};
    cout<<"Last stone weight : "<<s.lastStoneWeight(v)<<endl;
}   