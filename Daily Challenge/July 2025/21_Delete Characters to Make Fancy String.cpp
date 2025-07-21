class Solution {
public:
  string makeFancyString(string s) {
    int n = s.size();
    if (n < 3) return s;
    
    string result;
    result.reserve(n);
    
    for (int i = 0; i < n; ++i) {
      if (i >= 2 && s[i] == s[i - 1] && s[i] == s[i - 2]) {
        continue;
      }
      result.push_back(s[i]);
    }
    
    return result;
  }
};