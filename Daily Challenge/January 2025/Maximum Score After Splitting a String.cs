public class Solution {
  public int MaxScore(string s) {
    var countOne = 0;
    var countZero = 0;
    foreach (var c in s) {
      if (c == '1') countOne++;
    }

    var maxScore = 0;
    for (var i = 0; i < s.Length - 1; i++) {
      if (s[i] == '0') countZero++;
      else countOne--;
      maxScore = Math.Max(maxScore, countZero + countOne);
    }

    return maxScore;
  }
}