public class Solution {
  public int NumOfSubarrays(int[] arr) {
    int n = arr.Length;

    bool[] flag = new bool[n];
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += arr[i];
      flag[i] = sum % 2 == 1;
    }

    int[][] dp = new int[n + 1][];
    for (int i = 0; i < n + 1; ++i) {
      dp[i] = new int[2];
    }

    for (int i = n - 1; i >= 0; --i) {
      dp[i][0] = dp[i + 1][0];
      dp[i][1] = dp[i + 1][1];

      if (flag[i]) dp[i][1] += 1;
      else dp[i][0] += 1;
    }

    int subarrays = 0;
    for (int i = 0; i < n; ++i) {
      if (arr[i] % 2 == 1) {
        if (flag[i]) subarrays += dp[i][1];
        else subarrays += dp[i][0];
      } else {
        if (flag[i]) subarrays += dp[i][0];
        else subarrays += dp[i][1];
      }
      subarrays %= 1000000007;
    }

    return subarrays;
  }
}