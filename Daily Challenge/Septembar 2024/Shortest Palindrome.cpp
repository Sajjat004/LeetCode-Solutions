// Challenge Date: 20 Sep, 2024

class Solution {
  vector<int> prefixFunction(const string& s) {
    int n = (int) s.length();
    vector<int> LPS(n);

    for (int i = 1; i < n; i++) {
      int j = LPS[i - 1];

      while (j > 0 && s[i] != s[j]) {
        j = LPS[j - 1];
      }

      if (s[i] == s[j]) j++;
      LPS[i] = j;
    }

    return LPS;
  }
public:
  string shortestPalindrome(string s) {
    string reversedString = string(s.rbegin(), s.rend());
    string combinedString = s + "#" + reversedString;

    vector<int> LPS = prefixFunction(combinedString);

    int palindromeLength = LPS[combinedString.length() - 1];

    string suffix = reversedString.substr(0, s.length() - palindromeLength);

    return suffix + s;
  }
};