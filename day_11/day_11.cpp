#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int lsum = 0, rsum = 0;

        // Calculate the initial sum of the first k cards
        for (int i = 0; i < k; i++) {
            lsum += cardPoints[i];
        }

        int maxSum = lsum;

        // Use a sliding window to calculate the maximum score
        for (int i = 0; i < k; i++) {
            lsum -= cardPoints[k - 1 - i];
            rsum += cardPoints[n - 1 - i];
            maxSum = max(maxSum, lsum + rsum);
        }

        return maxSum;
    }
};

int main() {
    Solution sol;
    vector<int> cardPoints = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;
    cout << "Maximum score: " << sol.maxScore(cardPoints, k) << endl;
    return 0;
}
