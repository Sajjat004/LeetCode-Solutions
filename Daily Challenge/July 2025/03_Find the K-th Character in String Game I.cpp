class Solution {
  string next(const string& s) {
    string res = "";
    for (char c : s) {
      if (c == 'z') res += 'a';
      else res += c + 1;
    }
    return res;
  }

public:
  char kthCharacter(int k) {
    int n = 1;
    string s = "a";
    while (n < k) {
      s += next(s);
      n += n;
    }
    return s[k - 1];
  }
};