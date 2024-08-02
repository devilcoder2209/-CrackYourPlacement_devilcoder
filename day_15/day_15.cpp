#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxR = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (maxR < i) {
                return false;
            }
            maxR = max(maxR, i + nums[i]);
        }
        return true;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 3, 1, 1, 4}; // Example input
    bool result = solution.canJump(nums);
    cout << (result ? "Can jump to the end" : "Cannot jump to the end") << endl;
    return 0;
}
