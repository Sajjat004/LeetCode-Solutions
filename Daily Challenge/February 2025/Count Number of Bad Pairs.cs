public class Solution {
  public long CountBadPairs(int[] nums) {
    Dictionary<long, long> diffCount = new Dictionary<long, long>();
    long badPairs = 0;

    for (int i = 0; i < nums.Length; ++i) {
      long diff = i - nums[i];
      if (diffCount.ContainsKey(diff)) {
        badPairs += i - diffCount[diff];
        diffCount[diff]++;
      } else {
        badPairs += i;
        diffCount[diff] = 1;
      }
    }

    return badPairs;
  }
}