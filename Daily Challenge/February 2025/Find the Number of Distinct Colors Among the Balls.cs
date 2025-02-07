public class Solution {
  public int[] QueryResults(int limit, int[][] queries) {
    Dictionary<int, int> colorMap = new Dictionary<int, int>();
    Dictionary<int, int> balls = new Dictionary<int, int>();
    int[] result = new int[queries.Length];
    int distinctColors = 0;

    for (int i = 0; i < queries.Length; i++) {
      int ballColor = queries[i][1];
      int ballIndex = queries[i][0];
      
      if (balls.ContainsKey(ballIndex)) {
        colorMap[balls[ballIndex]]--;
        if (colorMap[balls[ballIndex]] == 0) distinctColors--;
        balls[ballIndex] = ballColor;

        if (colorMap.ContainsKey(ballColor)) {
          colorMap[ballColor]++;
        } else {
          colorMap.Add(ballColor, 1);
        }

        if (colorMap[ballColor] == 1) distinctColors++;
      } else {
        balls.Add(ballIndex, ballColor);

        if (colorMap.ContainsKey(ballColor)) {
          colorMap[ballColor]++;
        } else {
          colorMap.Add(ballColor, 1);
        }

        if (colorMap[ballColor] == 1) distinctColors++;
      }

      result[i] = distinctColors;
    }

    return result;
  }
}