#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return ""; // Handle empty input
        }

        // Find the shortest string
        int minLen = INT_MAX;
        for (const string& str : strs) {
            minLen = min(minLen, (int)str.length());
        }

        // Check for common prefix character by character
        for (int i = 0; i < minLen; ++i) {
            char c = strs[0][i];
            for (int j = 1; j < strs.size(); ++j) {
                if (strs[j][i] != c) {
                    return strs[0].substr(0, i); // Return the prefix found so far
                }
            }
        }

        // If we reach here, all strings share the entire shortest string as prefix
        return strs[0].substr(0, minLen);
    }
};

int main() {
    Solution solution;
    vector<string> strs = {"flower", "flow", "flight"};
    cout << "Longest Common Prefix: " << solution.longestCommonPrefix(strs) << endl;

    strs = {"dog", "racecar", "car"};
    cout << "Longest Common Prefix: " << solution.longestCommonPrefix(strs) << endl;

    strs = {"aa", "aaa"};
    cout << "Longest Common Prefix: " << solution.longestCommonPrefix(strs) << endl;

    return 0;
}
