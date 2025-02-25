class Solution {
  public:
    int numOfSubarrays(vector<int>& arr) {
      int n = arr.size();

      vector<bool> flag(n + 1, 0);
      int sum = 0;
      for (int i = 0; i < n; i++) {
        sum += arr[i];
        flag[i] = sum % 2;
      }

      vector<vector<int>> dp(n + 1, vector<int>(2, 0));
      for (int i = n - 1; i >= 0; --i) {
        dp[i][0] = dp[i + 1][0];
        dp[i][1] = dp[i + 1][1];

        if (flag[i]) dp[i][1]++;
        else dp[i][0]++;
      }

      long long ans = 0;
      for (int i = 0; i < n; ++i) {
        if (arr[i] & 1) {
          if (flag[i]) ans += dp[i][1];
          else ans += dp[i][0];
        } else {
          if (flag[i]) ans += dp[i][0];
          else ans += dp[i][1];
        }
        ans %= 1000000007;
      }

      return ans;
    }
  };