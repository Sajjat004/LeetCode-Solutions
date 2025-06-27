class Solution {
public:
  int subarraySum(vector<int>& nums) {
    int n = nums.size();
    vector<int> prefixSum(n, 0);
    prefixSum[0] = nums[0];
    for (int i = 1; i < n; ++i) {
      prefixSum[i] = prefixSum[i - 1] + nums[i];
    }

    int totalSubArraySum = 0;
    for (int i = 0; i < n; ++i) {
      int lastIndex = max(0, i - nums[i]);
      int sum = prefixSum[i] - (lastIndex > 0 ? prefixSum[lastIndex - 1] : 0);
      totalSubArraySum += sum;
    }

    return totalSubArraySum;
  }
};