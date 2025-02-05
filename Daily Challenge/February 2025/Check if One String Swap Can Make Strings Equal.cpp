class Solution {
public:
  bool areAlmostEqual(string s1, string s2) {
    int missMatchIndex1 = -1, missMatchIndex2 = -1;

    for (int i = 0; i < s1.size(); i++) {
      if (s1[i] != s2[i]) {
        if (missMatchIndex1 == -1) missMatchIndex1 = i;
        else if (missMatchIndex2 == -1) missMatchIndex2 = i;
        else return false;
      }
    }

    if (missMatchIndex1 == -1 and missMatchIndex2 == -1) return true;
    if (missMatchIndex1 == -1 or missMatchIndex2 == -1) return false;

    return s1[missMatchIndex1] == s2[missMatchIndex2] and s1[missMatchIndex2] == s2[missMatchIndex1];
  }
};