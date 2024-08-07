#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  bool isValid(string s) {
    stack<char> stack;

    for (const char c : s) {
      if (c == '(')
        stack.push(')');
      else if (c == '{')
        stack.push('}');
      else if (c == '[')
        stack.push(']');
      else if (stack.empty() || stack.top() != c) {
        return false;
      } else {
        stack.pop();
      }
    }

    return stack.empty();
  }
};

int main() {
  Solution solution;
  string test1 = "()";
  string test2 = "()[]{}";
  string test3 = "(]";
  string test4 = "([)]";
  string test5 = "{[]}";

  cout << solution.isValid(test1) << endl; // Output: 1 (true)
  cout << solution.isValid(test2) << endl; // Output: 1 (true)
  cout << solution.isValid(test3) << endl; // Output: 0 (false)
  cout << solution.isValid(test4) << endl; // Output: 0 (false)
  cout << solution.isValid(test5) << endl; // Output: 1 (true)

  return 0;
}
