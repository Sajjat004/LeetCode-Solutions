public class Solution {
  public int[] FindMissingAndRepeatedValues(int[][] grid) {
    int n = grid.Length;
    int[] frequency = new int[n * n + 1];

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        frequency[grid[i][j]]++;
      }
    }

    int missing = 0;
    int repeated = 0;

    for (int i = 1; i <= n * n; i++) {
      if (frequency[i] == 0) missing = i;
      if (frequency[i] == 2) repeated = i;
    }

    return new int[] {repeated, missing};
  }
}