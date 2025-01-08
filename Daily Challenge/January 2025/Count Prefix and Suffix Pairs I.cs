public class Solution {
  private bool isSuffixAndPrefix(string a, string b) {
    if (a.Length > b.Length) return false;

    for (int i = 0; i < a.Length; ++i) {
      if (a[i] != b[i] || a[i] != b[b.Length - a.Length + i]) return false;
    }

    return true;
  }

  public int CountPrefixSuffixPairs(string[] words) {
    int count = 0;

    for (int i = 0; i < words.Length; ++i) {
      for (int j = i + 1; j < words.Length; ++j) {
        if (isSuffixAndPrefix(words[i], words[j])) count++;
      }
    }

    return count;
  }
}