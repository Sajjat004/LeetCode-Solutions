public class Solution {
  public int LenLongestFibSubseq(int[] arr) {
    int n = arr.Length;
    var numSet = new HashSet<int>(arr);
    int maxLen = 0;

    for (int start = 0; start < n; ++start) {
      for (int next = start + 1; next < n; ++next) {
        int prev = arr[next];
        int curr = arr[start] + arr[next];
        int len = 2;

        while (numSet.Contains(curr)) {
          int temp = curr;
          curr += prev;
          prev = temp;
          ++len;
        }

        maxLen = Math.Max(maxLen, len);
      }
    }

    return maxLen > 2 ? maxLen : 0;
  }
}