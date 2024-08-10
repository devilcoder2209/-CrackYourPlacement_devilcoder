#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        int allowed_deletion = 1;

        while (left < right) {
            if (s[left] != s[right]) {
                if (!allowed_deletion) {
                    return false;
                }
                allowed_deletion--;
                // Try skipping left or right character
                return isPalindrome(s, left + 1, right) || isPalindrome(s, left, right - 1);
            }
            left++;
            right--;
        }
        return true;
    }

private:
    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Solution solution;
    string test1 = "abca";
    cout << "Is \"" << test1 << "\" a valid palindrome? " << (solution.validPalindrome(test1) ? "Yes" : "No") << endl;

    string test2 = "racecar";
    cout << "Is \"" << test2 << "\" a valid palindrome? " << (solution.validPalindrome(test2) ? "Yes" : "No") << endl;

    string test3 = "deeee";
    cout << "Is \"" << test3 << "\" a valid palindrome? " << (solution.validPalindrome(test3) ? "Yes" : "No") << endl;

    return 0;
}
