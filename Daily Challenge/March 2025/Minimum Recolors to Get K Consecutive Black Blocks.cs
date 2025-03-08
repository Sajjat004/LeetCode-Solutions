public class Solution {
  public int MinimumRecolors(string blocks, int k) {
    int n = blocks.Length;
    int[] prefixSumOfWhite = new int[n + 1];
    for (int i = 0; i < n; i++) {
      prefixSumOfWhite[i + 1] = prefixSumOfWhite[i] + (blocks[i] == 'W' ? 1 : 0);
    }

    int minOperations = int.MaxValue;
    for (int i = 1; i + k - 1 <= n; i++) {
      int operations = prefixSumOfWhite[i + k - 1] - prefixSumOfWhite[i - 1];
      minOperations = Math.Min(minOperations, operations);
    }

    return minOperations;
  }
}