public class Solution {
  public int NumberOfSubstrings(string s) {
    int n = s.Length;
    int[] count = new int[3];
    int left = 0, right = 0, res = 0;

    while (right < n) {
      count[s[right] - 'a']++;
      while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
        res += n - right;
        count[s[left] - 'a']--;
        left++;
      }
      right++;
    }

    return res;
  }
}