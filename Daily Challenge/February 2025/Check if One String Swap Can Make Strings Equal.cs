public class Solution {
  public bool AreAlmostEqual(string s1, string s2) {
    int missMatchIndex1 = -1;
    int missMatchIndex2 = -1;

    for (int i = 0; i < s1.Length; ++i) {
      if (s1[i] != s2[i]) {
        if (missMatchIndex1 == -1) missMatchIndex1 = i;
        else if (missMatchIndex2 == -1) missMatchIndex2 = i;
        else return false;
      }
    }

    if (missMatchIndex1 == -1 && missMatchIndex2 == -1) return true;
    if (missMatchIndex1 == -1 || missMatchIndex2 == -1) return false;

    return s1[missMatchIndex1] == s2[missMatchIndex2] && s1[missMatchIndex2] == s2[missMatchIndex1];
  }
}