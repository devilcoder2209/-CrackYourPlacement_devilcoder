#include <bits/stdc++.h>

using namespace std;

class Solution {
 public:
  string simplifyPath(string path) {
    string ans;
    istringstream iss(path);
    vector<string> stack;

    for (string dir; getline(iss, dir, '/');) {
      if (dir.empty() || dir == ".")
        continue;
      if (dir == "..") {
        if (!stack.empty())
          stack.pop_back();
      } else {
        stack.push_back(dir);
      }
    }

    for (const string& s : stack)
      ans += "/" + s;

    return ans.empty() ? "/" : ans;
  }
};

int main() {
  Solution solution;
  string path = "/a/./b/../../c/";
  cout << "Simplified Path: " << solution.simplifyPath(path) << endl;
  return 0;
}
