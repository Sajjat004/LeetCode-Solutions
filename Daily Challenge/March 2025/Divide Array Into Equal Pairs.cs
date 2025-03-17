public class Solution {
  public bool DivideArray(int[] nums) {
    Dictionary<int, int> counts = new Dictionary<int, int>();

    foreach (int num in nums) {
      if (!counts.ContainsKey(num)) {
        counts[num] = 0;
      }

      counts[num]++;
    }

    foreach (int count in counts.Values) {
      if (count % 2 != 0) {
        return false;
      }
    }

    return true;
  }
}