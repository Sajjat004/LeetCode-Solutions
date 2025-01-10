public class Solution {
  public IList<string> WordSubsets(string[] words1, string[] words2) {
    int[] maxFreq = new int[26];

    foreach (string word in words2) {
      int[] freq = new int[26];
      foreach (char c in word) {
        freq[c - 'a']++;
      }

      for (int i = 0; i < 26; i++) {
        maxFreq[i] = Math.Max(maxFreq[i], freq[i]);
      }
    }

    List<string> result = new List<string>();
    foreach (string word in words1) {
      int[] freq = new int[26];
      foreach (char c in word) {
        freq[c - 'a']++;
      }

      bool isUniversal = true;
      for (int i = 0; i < 26; i++) {
        if (freq[i] < maxFreq[i]) {
          isUniversal = false;
          break;
        }
      }

      if (isUniversal) {
        result.Add(word);
      }
    }

    return result;
  }
}