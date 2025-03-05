public class Solution {
  public long ColoredCells(int n) {
    long ans = (long) 1 * n * n * 2;
    ans -= (2 * n) - 1;

    return ans;
  }
}