class Solution {
public:
  int maxScore(string s) {
    int countOne = 0, countZero = 0;
    for (char c : s) {
      if (c == '1') countOne++;
    }

    int maxScore = 0;
    for (int i = 0; i < s.size() - 1; i++) {
      if (s[i] == '0') countZero++;
      else countOne--;
      maxScore = max(maxScore, countZero + countOne);
    }

    return maxScore;
  }
};