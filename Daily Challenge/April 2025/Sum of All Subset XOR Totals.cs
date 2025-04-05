public class Solution {
  public int SubsetXORSum(int[] nums) {
    int n = nums.Length;
    int totalXorSum = 0;
    
    for (int i = 0; i < (1 << n); i++) {
      int subsetXor = 0;
      for (int j = 0; j < n; j++) {
        if ((i & (1 << j)) != 0) {
          subsetXor ^= nums[j];
        }
      }
      totalXorSum += subsetXor;
    }

    return totalXorSum;
  }
}