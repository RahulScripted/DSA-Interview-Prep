// You are given an integer mountainHeight denoting the height of a mountain. You are also given an integer array workerTimes representing the work time of workers in seconds. The workers work simultaneously to reduce the height of the mountain. For worker i: To decrease the mountain's height by x, it takes workerTimes[i] + workerTimes[i] * 2 + ... + workerTimes[i] * x seconds. For example:

//     1 - To reduce the height of the mountain by 1, it takes workerTimes[i] seconds.

//     2 - To reduce the height of the mountain by 2, it takes workerTimes[i] + workerTimes[i] * 2 seconds, and so on.

// Return an integer representing the minimum number of seconds required for the workers to make the height of the mountain 0.







#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    typedef long long ll;
    bool solve(ll height,vector<int>&time,ll T){
        ll heightCanBeBreaken = 0;
        for(auto ti: time){
           ll h = (-1 + sqrt(1 + (8 * T) / ti)) / 2;
           heightCanBeBreaken += h;
           if(heightCanBeBreaken >= height)return true;
        }
        return false;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        ll low = 0,high = 1e18,ans = 1e18;
        while(low <= high){
            ll mid = low + (high - low) / 2;
            if(solve(1ll * mountainHeight, workerTimes, mid)){
                ans = mid;
                high = mid-1;
            } else low = mid + 1;
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> workerTimes = {1,2,3};
    cout << "Minimum number of seconds required: " << s.minNumberOfSeconds(6, workerTimes) << endl;
}