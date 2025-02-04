public class Solution {
  public int MaxAscendingSum(int[] nums) {
    int maxSum = 0;
    int sum = 0;

    for (int i = 0; i < nums.Length; i++) {
      if (i == 0 || nums[i] > nums[i - 1]) {
        sum += nums[i];
      } else {
        maxSum = Math.Max(maxSum, sum);
        sum = nums[i];
      }
    }

    return Math.Max(maxSum, sum);
  }
}