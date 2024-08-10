#include <bits/stdc++.h>

using namespace std;
class Solution {
 public:
  string intToRoman(int num) {
    const pair<int, string> valueSymbols[] = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};

    string roman;
    for (const auto& [value,symbol] : valueSymbols) {
      int count = num / value;
      num %= value;
      while (count--) {
        roman += symbol;
      }
    }
    return roman;
  }
};

int main() {
  Solution solution;
  vector<int> testCases = {3, 58, 1994, 2023, 3999};

  for (int num : testCases) {
    cout << "Integer: " << num << " -> Roman: " << solution.intToRoman(num) << endl;
  }

  return 0;
}
