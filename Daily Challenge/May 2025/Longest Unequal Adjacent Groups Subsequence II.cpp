class Solution {
public:
  vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
    int n = words.size();
    vector<int> dp(n + 1, 1);
    vector<int> next(n + 1, -1);

    auto isValid = [&] (int pos, int nextPos) {
      if (words[pos].size() != words[nextPos].size()) { return false; }

      int diff = 0;
      for (int i = 0; i < words[pos].size(); ++i) {
        diff += words[pos][i] != words[nextPos][i];
        if (diff > 1) { return false; }
      }

      return diff == 1 and groups[pos] != groups[nextPos];
    };

    for (int pos = n - 1; pos >= 0; --pos) {
      for (int nextPos = pos + 1; nextPos < n; ++nextPos) {
        if (isValid(pos, nextPos)) {
          if (dp[pos] < dp[nextPos] + 1) {
            dp[pos] = dp[nextPos] + 1;
            next[pos] = nextPos;
          }
        }
      }
    }

    int startIndex = 0, maxLength = 0;
    for (int i = 0; i < n; ++i) {
      if (dp[i] > maxLength) {
        maxLength = dp[i];
        startIndex = i;
      }
    }

    vector<string> result;
    while (startIndex != -1) {
      result.push_back(words[startIndex]);
      startIndex = next[startIndex];
    }

    return result;
  }
};