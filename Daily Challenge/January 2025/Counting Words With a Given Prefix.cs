public class Solution {
  private bool isPrefix(string word, string pref) {
    if (word.Length < pref.Length) return false;

    for (int i = 0; i < pref.Length; ++i) {
      if (word[i] != pref[i]) return false;
    }

    return true;
  }
  public int PrefixCount(string[] words, string pref) {
    int count = 0;
    for (int i = 0; i < words.Length; ++i) {
      if (isPrefix(words[i], pref)) count++;
    }

    return count;
  }
}