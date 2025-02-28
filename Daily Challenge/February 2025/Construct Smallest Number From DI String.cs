public class Solution {
  public string ShortestCommonSupersequence(string str1, string str2) {
    int n = str1.Length;
    int m = str2.Length;
    int[][] dp = new int[n + 1][];
    for (int i = 0; i <= n; ++i) {
      dp[i] = new int[m + 1];
      for (int j = 0; j <= m; ++j) {
        dp[i][j] = -1;
      }
    }
    
    dpCall(0, 0, str1, str2, dp);

    string result = "";
    int pos1 = 0, pos2 = 0;
    while (pos1 < n || pos2 < m) {
      if (pos1 == n) {
        result += str2[pos2++];
      } else if (pos2 == m) {
        result += str1[pos1++];
      } else if (str1[pos1] == str2[pos2]) {
        result += str1[pos1++];
        ++pos2;
      } else if (dp[pos1 + 1][pos2] < dp[pos1][pos2 + 1]) {
        result += str1[pos1++];
      } else {
        result += str2[pos2++];
      }
    }

    return result;
  }

  private int dpCall(int pos1, int pos2, string str1, string str2, int[][] dp) {
    if (pos1 == str1.Length) return dp[pos1][pos2] = str2.Length - pos2;
    if (pos2 == str2.Length) return dp[pos1][pos2] = str1.Length - pos1;
    if (dp[pos1][pos2] != -1) return dp[pos1][pos2];

    int mn = dpCall(pos1 + 1, pos2, str1, str2, dp) + 1;
    mn = Math.Min(mn, dpCall(pos1, pos2 + 1, str1, str2, dp) + 1);
    if (str1[pos1] == str2[pos2]) {
      mn = Math.Min(mn, dpCall(pos1 + 1, pos2 + 1, str1, str2, dp) + 1);
    }

    return dp[pos1][pos2] = mn;
  }
}