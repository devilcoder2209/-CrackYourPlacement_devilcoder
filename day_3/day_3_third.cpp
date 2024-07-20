#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long findMinDiff(long long m, long long n,vector<long long> a ) {
    // code
    sort(a.begin(), a.end());
    long long diff = 1e18;
    long long i = 0, j = i + (m - 1);
    while (j < n) {
      diff = min(diff, a[j] - a[i]);
      i++;
      j++;
    }

    return diff;
  }
};


int main() {
    Solution sol;
    long long n, m;
    cin >> n;

    vector<long long> arr(n);
    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cin >> m;

    long long result = sol.findMinDiff(m,n,arr);
    cout << result << endl;

    return 0;
}

