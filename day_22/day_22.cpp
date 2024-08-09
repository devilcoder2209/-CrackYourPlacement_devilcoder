#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        if (m == 0) return 0; // If s2 is empty, return 0
        if (n < m) return -1; // If s1 is shorter than s2, return -1

        const int base = 256; // Base value for the hash function
        const int mod = 101;  // A prime number to mod the hash values

        // Calculate the hash value of the pattern and the first window of the text
        int hash_s2 = 0, hash_s1 = 0, h = 1;
        for (int i = 0; i < m - 1; i++)
            h = (h * base) % mod;

        for (int i = 0; i < m; i++) {
            hash_s2 = (base * hash_s2 + s2[i]) % mod;
            hash_s1 = (base * hash_s1 + s1[i]) % mod;
        }

        // Slide the pattern over the text
        for (int i = 0; i <= n - m; i++) {
            // Check the hash values of the current window of text and the pattern
            if (hash_s1 == hash_s2) {
                // If the hash values match, check the characters one by one
                int j;
                for (j = 0; j < m; j++) {
                    if (s1[i + j] != s2[j])
                        break;
                }
                if (j == m)
                    return i; // Pattern found at index i
            }

            // Calculate the hash value for the next window of text
            if (i < n - m) {
                hash_s1 = (base * (hash_s1 - s1[i] * h) + s1[i + m]) % mod;
                if (hash_s1 < 0)
                    hash_s1 += mod;
            }
        }
        return -1; // Pattern not found
    }
};

int main() {
    Solution solution;
    string s1 = "hello";
    string s2 = "ll";
    int result = solution.strStr(s1, s2);
    cout << "The index of the first occurrence of '" << s2 << "' in '" << s1 << "' is: " << result << endl;

    s1 = "aaaaa";
    s2 = "bba";
    result = solution.strStr(s1, s2);
    cout << "The index of the first occurrence of '" << s2 << "' in '" << s1 << "' is: " << result << endl;

    s1 = "";
    s2 = "";
    result = solution.strStr(s1, s2);
    cout << "The index of the first occurrence of '" << s2 << "' in '" << s1 << "' is: " << result << endl;

    return 0;
}
