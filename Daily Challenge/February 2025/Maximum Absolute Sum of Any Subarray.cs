public class Solution {
  public int MaxAbsoluteSum(int[] nums) {
    int maxSum = MaxSubarraySum(nums);
    for (int i = 0; i < nums.Length; ++i) {
      nums[i] = -nums[i];
    }

    return Math.Max(maxSum, MaxSubarraySum(nums));
  }

  private int MaxSubarraySum(int[] nums) {
    int maxSum = int.MinValue;
    int minSum = 0;
    int sum = 0;

    foreach (int num in nums) {
      sum += num;
      maxSum = Math.Max(maxSum, sum - minSum);
      minSum = Math.Min(minSum, sum);
    }

    return Math.Abs(maxSum);
  }
}