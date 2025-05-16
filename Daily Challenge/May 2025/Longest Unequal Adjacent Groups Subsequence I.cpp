class Solution {
public:
  vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
    vector<string> result;
    int n = words.size();
    result.push_back(words[0]);
    int previous = groups[0];

    for (int i = 1; i < n; ++i) {
      if (groups[i] != previous) {
        result.push_back(words[i]);
        previous = groups[i];
      }
    }

    return result;
  }
};