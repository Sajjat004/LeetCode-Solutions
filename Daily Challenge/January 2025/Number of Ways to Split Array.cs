public class Solution {
  public int WaysToSplitArray(int[] nums) {
    int n = nums.Length;
    long[] prefixSum = new long[n];

    for (int i = 0; i < n; ++i) {
      prefixSum[i] = nums[i] + (i > 0 ? prefixSum[i - 1] : 0);
    }

    int splits = 0;
    for (int i = 0; i < (n - 1); ++i) {
      if (prefixSum[i] >= prefixSum[n - 1] - prefixSum[i]) splits++;
    }

    return splits;
  }
}