public class Solution {
  private bool isSubstring(ref string a, ref string b) {
    return a.Length <= b.Length && b.IndexOf(a) != -1;
  }

  public IList<string> StringMatching(string[] words) {
    List<string> result = new List<string>();

    for (int i = 0; i < words.Length; ++i) {
      for (int j = 0; j < words.Length; ++j) {
        if (i != j && isSubstring(ref words[i], ref words[j])) {
          result.Add(words[i]);
          break;
        }
      }
    }

    return result;
  }
}