class Solution {
  bool isdigit(char c) {
    return c >= '0' && c <= '9';
  }

public:
  string clearDigits(string s) {
    int n = s.size();
    int countDigits = 0;

    string result = "";
    for (int i = n - 1; i >= 0; --i) {
      if (isdigit(s[i])) {
        countDigits++;
      } else {
        if (countDigits == 0) {
          result += s[i];
        } else {
          countDigits--;
        }
      }
    }

    reverse(result.begin(), result.end());

    return result;
  }
};