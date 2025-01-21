public class Solution {
  public long GridGame(int[][] grid) {
    int n = grid[0].Length;

    long[][] prefixSum = new long[2][];
    prefixSum[0] = new long[n];
    prefixSum[1] = new long[n];

    for (int i = 0; i < n; i++) {
      prefixSum[0][i] = grid[0][i] + (i == 0 ? 0 : prefixSum[0][i - 1]);
      prefixSum[1][i] = grid[1][i] + (i == 0 ? 0 : prefixSum[1][i - 1]);
    }

    long result = long.MaxValue;
    for (int i = 0; i < n; i++) {
      long top = prefixSum[0][n - 1] - prefixSum[0][i];
      long bottom = i == 0 ? 0 : prefixSum[1][i - 1];
      result = Math.Min(result, Math.Max(top, bottom));
    }

    return result;
  }
}