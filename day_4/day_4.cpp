#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> mpp;
    for (int i = 0; i < nums.size(); i++) {
      int first = nums[i];
      int moreNeeded = target - nums[i];
      if (mpp.find(moreNeeded) != mpp.end()) {
        return {mpp[moreNeeded], i};
      }
      mpp[first] = i;
    }
    return {-1, -1};
  }
};

int main() {
  Solution solution;
  int n, target;

  // Check if input for n is successful
  if (!(cin >> n)) {
    return 1;
  }

  vector<int> nums(n);

  // Check if input for each element is successful
  for (int i = 0; i < n; i++) {
    if (!(cin >> nums[i])) {
      cerr << i + 1 << endl;
      return 1;
    }
  }

  // Check if input for target is successful
  if (!(cin >> target)) {
    cerr << endl;
    return 1;
  }

  vector<int> result = solution.twoSum(nums, target);
  if (result[0] != -1) {
    cout << result[0] << " " << result[1] << endl;
  } else {
    cout << endl;
  }

  return 0;
}
