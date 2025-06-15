class Solution {
public:
  long long maxSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    long long maxSum = LLONG_MIN;
    long long currentSum = 0;
    vector<long long> minSum(n + 1, LLONG_MAX);
    minSum[0] = 0;

    for (int i = 0; i < n; ++i) {
      currentSum += nums[i];
      if ((i + 1) >= k) {
        maxSum = max(maxSum, currentSum - minSum[(i + 1) % k]);
      }
      minSum[(i + 1) % k] = min(minSum[(i + 1) % k], currentSum);
    }

    return maxSum;
  }
};