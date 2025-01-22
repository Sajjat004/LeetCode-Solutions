public class Solution {
  public int[][] HighestPeak(int[][] isWater) {
    int n = isWater.Length;
    int m = isWater[0].Length;
    int[][] result = new int[n][];
    for (int i = 0; i < n; i++) {
      result[i] = new int[m];
      for (int j = 0; j < m; j++) {
        result[i][j] = -1;
      }
    }

    Queue<int[]> queue = new Queue<int[]>();
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (isWater[i][j] == 1) {
          queue.Enqueue(new int[] { i, j });
          result[i][j] = 0;
        }
      }
    }

    var isValid = new Func<int, int, bool>((x, y) => x >= 0 && x < n && y >= 0 && y < m);

    int[] dx = new int[] { 0, 0, 1, -1 };
    int[] dy = new int[] { 1, -1, 0, 0 };
    while (queue.Count > 0) {
      int[] current = queue.Dequeue();
      int x = current[0];
      int y = current[1];
      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (isValid(nx, ny) && result[nx][ny] == -1) {
          result[nx][ny] = result[x][y] + 1;
          queue.Enqueue(new int[] { nx, ny });
        }
      }
    }

    return result;
  }
}