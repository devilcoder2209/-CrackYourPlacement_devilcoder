#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Initialize slow and fast pointers
        int slow = nums[0];
        int fast = nums[0];

        // Phase 1: Find the intersection point of the two pointers
        do {
            slow = nums[slow];              // Move slow pointer by one step
            fast = nums[nums[fast]];       // Move fast pointer by two steps
        } while (slow != fast);

        // Phase 2: Find the entrance to the cycle
        fast = nums[0];                     // Reset fast pointer to start of array
        while (slow != fast) {
            slow = nums[slow];              // Move both pointers at the same speed
            fast = nums[fast];
        }

        // At this point, slow and fast meet at the entrance to the cycle
        return fast;                        // Return the duplicate number
    }
};

int main() {
    // Input the size of the array
    int n;
    cin >> n;

    // Input the elements of the array
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    // Create an object of the Solution class
    Solution solution;

    // Call the findDuplicate function and store the result
    int duplicate = solution.findDuplicate(nums);

    // Print the duplicate element
    cout << duplicate;

    return 0;
}
