public class Solution {
  public int MaximumCount(int[] nums) {
    int positive = 0;
    int negative = 0;

    foreach (var num in nums) {
      if (num > 0) {
        positive++;
      } else if (num < 0) {
        negative++;
      }
    }
    
    return Math.Max(positive, negative);
  }
}