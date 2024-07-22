#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0 ; 

        for(int i = 1 ; i< prices.size();i++){
            if (prices[i]>prices[i-1])
                profit += (prices[i]-prices[i-1]);
        }
        return profit;
    }
};

int main (){
    int n;
    cin >> n;
    vector<int> prices(n);

    for (int i = 0 ; i< prices.size() ;i++) {
        cin >> prices[i];
    }

    Solution s;

    int ans = s.maxProfit(prices);
    cout << ans << endl;
}