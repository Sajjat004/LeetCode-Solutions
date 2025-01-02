public class Solution {
  private bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }

  private bool isValid(string s) {
    return isVowel(s[0]) && isVowel(s[s.Length - 1]);
  }

  public int[] VowelStrings(string[] words, int[][] queries) {
    int[] prefix = new int[words.Length];

    for (int i = 0; i < words.Length; ++i) {
      prefix[i] = (i > 0 ? prefix[i - 1] : 0) + (isValid(words[i]) ? 1 : 0);
    }

    int[] result = new int[queries.Length];
    for (int i = 0; i < queries.Length; ++i) {
      int l = queries[i][0], r = queries[i][1];
      result[i] = prefix[r] - (l > 0 ? prefix[l - 1] : 0);
    }

    return result;
  }
}