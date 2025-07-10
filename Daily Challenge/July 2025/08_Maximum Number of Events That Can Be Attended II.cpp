class Solution {
public:
  int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    for (int i = n - 1; i >= 0; --i) {
      for (int t = 1; t <= k; ++t) {
        dp[i][t] = dp[i + 1][t];
        for (int j = i + 1; j < n; ++j) {
          if (prices[j] > prices[i]) {
            dp[i][t] = max(dp[i][t], prices[j] - prices[i] + dp[j + 1][t - 1]);
          }
        }
      }
    }
    return dp[0][k];
  }
};