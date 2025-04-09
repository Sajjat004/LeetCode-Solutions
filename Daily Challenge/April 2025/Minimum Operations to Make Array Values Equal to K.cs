public class Solution {
  public int MinOperations(int[] nums, int k) {
    var set = new HashSet<int>();
    foreach (var num in nums) {
      set.Add(num);
    }

    int operations = 0;
    foreach (var num in set) {
      if (num < k) return -1;
      if (num > k) operations++;
    }

    return operations;
  }
}