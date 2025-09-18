class Solution {
public:
  double soupServings(int n) {
    int m = (n + 24) / 25;
    unordered_map<int, unordered_map<int, double>> dp;

    function<double(int, int)> calculate = [&](int i, int j) -> double {
      return (dp[max(0, i - 4)][j] +
              dp[max(0, i - 3)][max(0, j - 1)] +
              dp[max(0, i - 2)][max(0, j - 2)] +
              dp[max(0, i - 1)][max(0, j - 3)]) / 4.0;
    };

    dp[0][0] = 0.5;
    for (int i = 1; i <= m; ++i) {
      dp[0][i] = 1.0;
      dp[i][0] = 0.0;
      for (int j = 1; j <= i; ++j) {
        dp[j][i] = calculate(j, i);
        dp[i][j] = calculate(i, j);
      }
      if (dp[i][i] > (1.0 - 1e-5)) return 1.0;
    }
    return dp[m][m];
  }
};