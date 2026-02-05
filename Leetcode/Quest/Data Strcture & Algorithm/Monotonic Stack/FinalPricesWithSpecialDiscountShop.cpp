// You are given an integer array prices where prices[i] is the price of the ith item in a shop. There is a special discount for items in the shop. If you buy the ith item, then you will receive a discount equivalent to prices[j] where j is the minimum index such that j > i and prices[j] <= prices[i]. Otherwise, you will not receive any discount at all. Return an integer array answer where answer[i] is the final price you will pay for the ith item of the shop, considering the special discount.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int>st;
        int n = prices.size();

        for(int i = (n - 1);i >= 0;i--){
            int x = prices[i];
            while(!st.empty() && st.top() > x) st.pop();
            if(!st.empty()) prices[i] -= st.top();
            st.push(x);
        }
        return prices;
    }
};

int main(){
    Solution sol;
    vector<int> prices = {8,4,6,2,3};
    vector<int> result = sol.finalPrices(prices);
    cout<<"Final Prices: ";
    for(int price : result) cout << price << " ";
}