class Solution {
  bool checkSubString(const string& s1, const string& s2) {
    int n = s1.size();
    int m = s2.size();
    if (n < m) return false;
    for (int i = 0; i <= n - m; i++) {
      if (s1.substr(i, m) == s2) return true;
    }

    return false;
  }

public:
  vector<string> stringMatching(vector<string>& words) {
    vector<string> res;

    for (int i = 0; i < words.size(); i++) {
      for (int j = 0; j < words.size(); j++) {
        if (i == j) continue;
        if (checkSubString(words[j], words[i])) {
          res.push_back(words[i]);
          break;
        }
      }
    }

    return res;
  }
};