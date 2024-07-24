#include <iostream>
#include <vector>
#include <algorithm> // For sort function

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1])
                ans.push_back(nums[i]);
        }
        return ans;
    }
};

int main() {
    Solution solution;
    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> duplicates = solution.findDuplicates(nums);

    for (int num : duplicates) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
