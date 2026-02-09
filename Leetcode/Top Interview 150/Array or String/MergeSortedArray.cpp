// You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively. Merge nums1 and nums2 into a single array sorted in non-decreasing order.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int mIdx = m - 1, nIdx = n - 1, right = (m + n) - 1;

        while(nIdx >= 0){
            if(mIdx >= 0 && nums1[mIdx] > nums2[nIdx]){
                nums1[right] = nums1[mIdx];
                mIdx--;
            }
            else{
                nums1[right] = nums2[nIdx];
                nIdx--;
            }
            right--;
        }
    }
};

int main(){
    Solution sol;
    vector<int> nums1 = {1,2,3,0,0,0}, nums2 = {2,5,6};
    int m = 3, n = 3;
    sol.merge(nums1, m, nums2, n);
    cout<<"After sorting : ";
    for(int i : nums1) cout << i << " ";
}