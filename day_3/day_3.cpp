#include <bits/stdc++.h>

using namespace std;

void moveZeroes(vector<int>& nums);

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                j = i;
                break;
            }
        }

        if (j == -1) return;

        for (int i = j + 1; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};



int main() {
  int n;

  cin >> n;

  vector<int> arr(n);

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  Solution sol;
  sol.moveZeroes(arr);

  for (int i = 0; i < arr.size(); i++) {
    cout << arr[i] << " ";
  }

  return 0;
}