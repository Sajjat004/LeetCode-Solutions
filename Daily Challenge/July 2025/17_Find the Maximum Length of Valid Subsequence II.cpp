class Solution {
public:
  int maximumLength(vector<int>& nums, int k) {
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 1));
    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        int mod = (nums[i] + nums[j]) % k;
        dp[i][mod] = max(dp[i][mod], dp[j][mod] + 1);
      }
    }
    int mxLen = 1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j <= k; ++j) {
        mxLen = max(mxLen, dp[i][j]);
      }
    }
    return mxLen;
  }
};