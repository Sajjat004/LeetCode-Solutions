class Solution {
public:
  long long gridGame(vector<vector<int>>& grid) {
    int n = grid[0].size();
    vector<vector<long long>> prefixSum(2, vector<long long>(n, 0));

    for (int i = 0; i < n; ++i) {
      prefixSum[0][i] = grid[0][i] + (i > 0 ? prefixSum[0][i - 1] : 0);
      prefixSum[1][i] = grid[1][i] + (i > 0 ? prefixSum[1][i - 1] : 0);
    }

    long long ans = LLONG_MAX;
    for (int i = 0; i < n; ++i) {
      long long top = prefixSum[0][n - 1] - prefixSum[0][i];
      long long bottom = (i > 0 ? prefixSum[1][i - 1] : 0);
      ans = min(ans, max(top, bottom));
    }

    return ans;
  }
};