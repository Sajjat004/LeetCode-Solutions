class Solution {
public:
  string shortestCommonSupersequence(string str1, string str2) {
    int n = str1.size(), m = str2.size();
    vector<vector<int>> dp(n + 5, vector<int>(m + 5, -1));
    dpCall(0, 0, str1, str2, dp);

    string result = "";
    int pos1 = 0, pos2 = 0;
    while (pos1 < n || pos2 < m) {
      if (pos1 == n) {
        result += str2[pos2];
        pos2++;
      } else if (pos2 == m) {
        result += str1[pos1];
        pos1++;
      } else if (str1[pos1] == str2[pos2]) {
        result += str1[pos1];
        pos1++;
        pos2++;
      } else if (dp[pos1 + 1][pos2] < dp[pos1][pos2 + 1]) {
        result += str1[pos1];
        pos1++;
      } else {
        result += str2[pos2];
        pos2++;
      }
    }

    return result;
  }

private:
  int dpCall(int pos1, int pos2, string &str1, string &str2, vector<vector<int>> &dp) {
    if (pos1 == str1.size()) return dp[pos1][pos2] = str2.size() - pos2;
    if (pos2 == str2.size()) return dp[pos1][pos2] = str1.size() - pos1;
    if (dp[pos1][pos2] != -1) return dp[pos1][pos2];
    int restPart = dpCall(pos1 + 1, pos2, str1, str2, dp) + 1;
    restPart = min(restPart, dpCall(pos1, pos2 + 1, str1, str2, dp) + 1);
    if (str1[pos1] == str2[pos2]) {
      restPart = min(restPart, dpCall(pos1 + 1, pos2 + 1, str1, str2, dp) + 1);
    }

    return dp[pos1][pos2] = restPart;
  }
};