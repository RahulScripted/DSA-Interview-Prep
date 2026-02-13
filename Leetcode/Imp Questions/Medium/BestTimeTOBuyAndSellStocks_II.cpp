// You are given an integer array prices where prices[i] is the price of a given stock on the ith day. On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can sell and buy the stock multiple times on the same day, ensuring you never hold more than one share of the stock. Find and return the maximum profit you can achieve.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) profit += prices[i] - prices[i - 1];
        }
        
        return profit;
    }
};

int main() {
    Solution solution;

    vector<int> prices1 = {7, 1, 5, 3, 6, 4};
    cout << "Maximum profit : ";
    cout << solution.maxProfit(prices1) << endl; 

    vector<int> prices2 = {1, 2, 3, 4, 5};
    cout << "Maximum profit : ";
    cout << solution.maxProfit(prices2) << endl;

    vector<int> prices3 = {7, 6, 4, 3, 1};
    cout << "Maximum profit : ";
    cout << solution.maxProfit(prices3) << endl;
}