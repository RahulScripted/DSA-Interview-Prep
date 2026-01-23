// You are given an array prices where prices[i] is the price of a given stock on the ith day. You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock. Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyPrice = prices[0], profit = 0;
        for(int price : prices){
            if(buyPrice > price) buyPrice = price;
            profit = max(profit, price - buyPrice);
        }
        return profit;
    }
};

int main(){
    Solution sol;
    vector<int> prices = {7,1,5,3,6,4};
    cout<<"Profit is: ";
    cout << sol.maxProfit(prices) << endl;

    prices = {7,6,4,3,1};
    cout<<"Profit is: ";
    cout << sol.maxProfit(prices) << endl;
}