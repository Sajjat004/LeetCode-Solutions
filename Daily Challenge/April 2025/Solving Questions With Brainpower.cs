public class Solution {
  public long MostPoints(int[][] questions) {
    int n = questions.Length;
    long[] dp = new long[n + 1];

    for (int i = n - 1; i >= 0; i--) {
      int nextQuestion = i + questions[i][1] + 1;
      dp[i] = Math.Max(dp[i + 1], questions[i][0] + (nextQuestion < n ? dp[nextQuestion] : 0));
    }
    
    return dp[0];
  }
}