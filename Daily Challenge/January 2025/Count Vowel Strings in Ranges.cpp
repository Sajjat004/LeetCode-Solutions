class Solution {
  bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }

  bool check(string& s) {
    return isVowel(s[0]) && isVowel(s.back());
  }

public:
  vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
    vector<int> prefix(words.size(), 0);
    for (int i = 0; i < words.size(); ++i) {
      prefix[i] = check(words[i]);
      if (i > 0) {
        prefix[i] += prefix[i - 1];
      }
    }

    vector<int> res;
    for (auto& q : queries) {
      int l = q[0], r = q[1];
      int cnt = prefix[r] - (l > 0 ? prefix[l - 1] : 0);
      res.push_back(cnt);
    }

    return res;
  }
};