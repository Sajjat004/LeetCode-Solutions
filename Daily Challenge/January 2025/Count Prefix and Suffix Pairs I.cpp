class Solution {
  bool isPrefixAndSuffix(const string& a, const string& b) {
    if (a.size() > b.size()) return false;

    for (int i = 0; i < a.size(); i++) {
      if (a[i] != b[i] or a[i] != b[b.size() - a.size() + i]) {
        return false;
      }
    }

    return true;
  }
public:
  int countPrefixSuffixPairs(vector<string>& words) {
    int count = 0;

    for (int i = 0; i < words.size(); ++i) {
      for (int j = i + 1; j < words.size(); ++j) {
        if (isPrefixAndSuffix(words[i], words[j])) count++;
      }
    }

    return count;
  }
};