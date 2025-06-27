class Solution {
  long long dpCall(int index, int leftColor, int rightColor, int n, vector<vector<int>>& cost, vector<vector<vector<long long>>>& dp) {
    if (index >= (n / 2)) return 0;
    if (leftColor != -1 and rightColor != -1 and dp[index][leftColor][rightColor] != -1) return dp[index][leftColor][rightColor];
    long long ans = LLONG_MAX;

    for (int lc = 0; lc < 3; ++lc) {
      for (int rc = 0; rc < 3; ++rc) {
        if (lc == rc or lc == leftColor || rc == rightColor) continue;
        long long costValue = cost[index][lc] + cost[n - index - 1][rc];
        long long subProblem = dpCall(index + 1, lc, rc, n, cost, dp);
        ans = min(ans, costValue + subProblem);
      }
    }
    if (leftColor == -1 && rightColor == -1) {
      return ans;
    }
    return dp[index][leftColor][rightColor] = ans;
  }

public:
  long long minCost(int n, vector<vector<int>>& cost) {
    vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(3, vector<long long>(3, -1)));
    return dpCall(0, -1, -1, n, cost, dp);
  }
};