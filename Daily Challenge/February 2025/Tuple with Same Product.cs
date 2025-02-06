public class Solution {
  public int TupleSameProduct(int[] nums) {
    int n = nums.Length;
    Dictionary<int, int> count = new Dictionary<int, int>();

    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        int product = nums[i] * nums[j];
        count[product] = 1 + (count.ContainsKey(product) ? count[product] : 0);
      }
    }

    int tuples = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        int product = nums[i] * nums[j];

        if (count.ContainsKey(product) && count[product] >= 2) {
          tuples += (4 * (count[product] - 1));
        }
      }
    }

    return tuples;
  }
}