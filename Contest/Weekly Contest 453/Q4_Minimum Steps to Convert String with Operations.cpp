class Solution {
  int operationInSubString(string word1, string word2) {
    int n = word1.size();
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (word1[i] == word2[i]) continue;
      for (int j = i + 1; j < n; ++j) {
        if (word1[i] == word2[j] && word1[j] == word2[i]) {
          cnt++;
          swap(word1[i], word1[j]);
          break;
        }
      }
      if (word1[i] != word2[i]) {
        cnt++;
      }
    }

    return cnt;
  }
  
  int findMinOperations(int index, string& word1, string& word2, vector<int>& dp) {
    if (index == (int) word1.size()) return 0;
    if (dp[index] != -1) return dp[index];
    int ans = 0;
    if (word1[index] == word2[index]) ans = findMinOperations(index + 1, word1, word2, dp);
    else ans = 1 + findMinOperations(index + 1, word1, word2, dp);

    string temp1 = "", temp2 = "";
    temp1 += word1[index];
    temp2 += word2[index];

    for (int i = index + 1; i < (int) word1.size(); ++i) {
      temp1 += word1[i];
      temp2 += word2[i];
      int operations = operationInSubString(temp1, temp2);
      ans = min(ans, operations + findMinOperations(i + 1, word1, word2, dp));
      reverse(temp1.begin(), temp1.end());
      operations = operationInSubString(temp1, temp2) + 1;
      ans = min(ans, operations + findMinOperations(i + 1, word1, word2, dp));
      reverse(temp1.begin(), temp1.end());
    }

    return dp[index] = ans;
  }

public:
  int minOperations(string word1, string word2) {
    int n = word1.size();
    vector<int> dp(n, -1);

    return findMinOperations(0, word1, word2, dp);
  }
};