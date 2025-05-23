class Solution {
public:
  long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
    vector<long long> netChange;
    int n = nums.size();
    long long nodeSum = 0;
    for (int i = 0; i < n; ++i) {
      long long change = (nums[i] ^ k) - nums[i];
      netChange.push_back(change);
      nodeSum += nums[i];
    }
    sort(netChange.begin(), netChange.end(), greater<long long>());

    for (int i = 0; i < netChange.size(); i += 2) {
      if (i + 1 >= netChange.size()) break;
      long long pairSum = netChange[i] + netChange[i + 1];
      if (pairSum > 0) nodeSum += pairSum;
      else break;
    }

    return nodeSum;
  }
};

// DP solution
class Solution {
  long long maxSumOfNodes(int index, int isEven, int k, vector<int>& nums, vector<vector<long long>>& memo) {
    if (index == nums.size()) return isEven == 1 ? 0 : LLONG_MIN;
    if (memo[index][isEven] != -1) return memo[index][isEven];

    long long xorDone =(nums[index] ^ k) + maxSumOfNodes(index + 1, isEven ^ 1, k, nums, memo);
    long long xorNotDone = nums[index] + maxSumOfNodes(index + 1, isEven, k, nums, memo);

    return memo[index][isEven] = max(xorDone, xorNotDone);
  }
public:
  long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
    int n = nums.size();
    vector<vector<long long>> memo(n, vector<long long>(2, -1));

    return maxSumOfNodes(0, 1, k, nums, memo);
  }
};

// Iterative DP
class Solution {
public:
  long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
    int n = nums.size();
    vector<vector<long long>> dp(n + 1, vector<long long>(2, LLONG_MIN));
    dp[n][0] = LLONG_MIN;
    dp[n][1] = 0;

    for (int index = n - 1; index >= 0; --index) {
      for (int isEven = 0; isEven < 2; ++isEven) {
        long long xorDone = (nums[index] ^ k) + dp[index + 1][isEven ^ 1];
        long long xorNotDone = nums[index] + dp[index + 1][isEven];
        dp[index][isEven] = max(xorDone, xorNotDone);
      }
    }

    return dp[0][1];
  }
};