#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mpp_rem;
        mpp_rem[0] = 1;

        int Prefix=0,rem,total = 0;

        for (auto i = 0 ;i < nums.size();i++){
            Prefix += nums[i];

            rem = (Prefix % k + k) % k;

            total += mpp_rem[rem];
            mpp_rem[rem]++;
        }
        return total;
    }
};

int main(){
    int n,k ; cin>> n>>k;
    vector<int> nums(n);

    for (int i = 0 ; i < n ; i++) {
        cin >> nums[i];
    }
    
    Solution s1;
    //s1.subarraysDivByK(nums,n); 

    int ans = s1.subarraysDivByK(nums,k);

    cout << ans << endl;

}