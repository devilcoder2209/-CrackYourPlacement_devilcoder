#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int sortColors(vector<int>& nums) {
        int start= 0, mid = 0, end = nums.size() - 1 ;
        while (mid <= end ){
            if (nums[mid] == 0){
                swap(nums[start], nums[mid]);
                start++; mid++;
            }
            else if (nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid],nums[end]);
                end--;
            }
        }
        return 0;
    }
};

int main(){
int n;

  cin >> n;

  // Create an empty vector to store user input
  vector<int> nums(n);

  // Get user input for each element (validate input)
  for (int i = 0; i < n; ++i) {
    int color;
    cin >> color;

    // Validate user input (0, 1, or 2 only)
    while (color < 0 || color > 2) {
      cin >> color;
    }

    nums[i] = color;
  }

  // Create an object of the Solution class
  Solution solution;

  // Call the sortColors function to sort the vector in-place
  solution.sortColors(nums);

  // Print the sorted vector
  cout << "Sorted colors: ";
  for (int color : nums) {
    cout << color << " ";
  }
  cout << endl;

  return 0;
}