#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       int count= 0;
       for (int i =0 ; i< nums.size() ; i++){
        if (i < nums.size()-1 && nums [i] == nums [i+1])
        { continue;}
        else{
            nums[count] =nums[i];
            count++;
        }
        }
       return count;
    }
};


int main() {
    vector<int> nums;
    int num;

    while (cin >> num) {
        nums.push_back(num);
    }

    int newLength = Solution().removeDuplicates(nums);

    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}