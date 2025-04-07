class Solution {
  public:
    bool fun(int pos, int n, int sum, vector<int>& nums, vector<vector<int>>& dp) {
      if (sum == 0) return 1;
      if (sum < 0) return 0;
      if (pos == n) return 0;
      if (dp[pos][sum] != -1) return dp[pos][sum];
      bool ok = fun(pos + 1, n, sum, nums, dp);
      ok |= fun(pos + 1, n, sum - nums[pos], nums, dp);
      return dp[pos][sum] = ok;
    }
    bool canPartition(vector<int>& nums) {
      int sum = 0;
      for (int x : nums) sum += x;
      if (sum & 1) return 0;
      vector<vector<int>> dp(202, vector<int>(20002, -1));
      return fun(0, nums.size(), sum / 2, nums, dp);
    }
  };