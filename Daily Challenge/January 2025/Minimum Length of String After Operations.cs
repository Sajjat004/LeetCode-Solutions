public class Solution {
  public int MinimumLength(string s) {
    int[] freq = new int[26];
    foreach (char c in s) {
      freq[c - 'a']++;
    }

    int ans = 0;
    for (int i = 0; i < 26; ++i) {
      if (freq[i] > 0 && freq[i] % 2 == 0) ans += 2;
      else if (freq[i] > 0 && freq[i] % 2 == 1) ans += 1;
    }

    return ans;
  }
}