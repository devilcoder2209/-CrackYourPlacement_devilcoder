#include <bits/stdc++.h>

using namespace std;

int maxProfit(vector<int>& Arr);
class Solution {
public:
    int maxProfit(vector<int>& Arr) {
    int maxProfit = 0;
	int mini = Arr[0];
	
	for(int i=1;i<Arr.size();i++){
        int curProfit = Arr[i] - mini;
        maxProfit = max(maxProfit,curProfit);
        mini = min(mini,Arr[i]);
        }
	return maxProfit;
    }
};

int main() {
  int n;

  cin >> n;

  vector<int> prices(n);

  for (int i = 0; i < n; i++) {
    cin >> prices[i];
  }

  Solution sol;
  int profit = sol.maxProfit(prices);

  cout << profit << endl;

  return 0;
}