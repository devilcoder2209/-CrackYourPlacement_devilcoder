#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i=0; i < nums.size()-2;i++){

            if(i==0 || (i > 0 && nums[i] !=nums[i-1]))  {

            int lo = i+1, hi =nums.size()-1, sum = 0-nums[i];

            while(lo < hi){
                if(nums[lo] + nums[hi] == sum) {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[lo]);
                    temp.push_back(nums[hi]);
                    res.push_back(temp);

                    while(lo < hi  && nums[lo]==nums[lo+1]) lo++;
                    while(lo < hi && nums[hi] == nums[hi-1]) hi--;

                    lo++;  hi--;

                }
                else if (nums[lo]+ nums[hi] < sum) lo++;
                else hi--;
            }
                
            } 
        }
        return res;
        
    }
};

int main() {
    int n;
    cin >> n;  // Read the size of the array
    vector<int> nums(n);

    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    Solution sol;
    vector<vector<int>> result = sol.threeSum(nums);

    // Print the result
    for (const auto& triplet : result) {
        cout << "[";
        for (int i = 0; i < triplet.size(); ++i) {
            cout << triplet[i];
            if (i != triplet.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    return 0;
}
