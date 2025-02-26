class Solution {
public:
  int maxAbsoluteSum(vector<int>& nums) {
    int maxSum = maxSubarraySum(nums);
    for (int& num : nums) {
      num *= -1;
    }
    
    return max(maxSum, maxSubarraySum(nums));
  }

private:
  int maxSubarraySum(vector<int>& nums) {
    int maxSum = INT_MIN;
    int minSum = 0;
    int sum = 0;

    for (int num : nums) {
      sum += num;
      maxSum = max(maxSum, sum - minSum);
      minSum = min(minSum, sum);
    }

    return abs(maxSum);
  }
};