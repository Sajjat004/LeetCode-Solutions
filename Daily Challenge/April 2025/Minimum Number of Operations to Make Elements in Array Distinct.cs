public class Solution {
  public int MinimumOperations(int[] nums) {
    int left = 0;
    int operations = 0;

    while (!isDistinct(nums, left)) {
      operations++;
      left += 3;
    }

    return operations;
  }

  private bool isDistinct(int[] nums, int left) {
    HashSet<int> set = new HashSet<int>();
    for (int i = left; i < nums.Length; ++i) {
      if (set.Contains(nums[i])) return false;
      set.Add(nums[i]);
    }

    return true;
  }
}