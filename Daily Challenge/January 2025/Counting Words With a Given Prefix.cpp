class Solution {
  bool isPrefix(const string& word, const string& pref) {
    if (word.size() < pref.size()) return false;
    for (int i = 0; i < pref.size(); ++i) {
      if (word[i] != pref[i]) return false;
    }

    return true;
  }
public:
  int prefixCount(vector<string>& words, string pref) {
    int count = 0;
    for (const string& word : words) {
      if (isPrefix(word, pref)) {
        ++count;
      }
    }

    return count;
  }
};