public class Solution {

  private bool[][] visited;
  private int[] dx = new int[] {0, 0, 1, -1};
  private int[] dy = new int[] {1, -1, 0, 0};

  private bool IsValid(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
  }

  private int DFS(int x, int y, int[][] grid) {
    visited[x][y] = true;

    int fish = grid[x][y];
    for (int i = 0; i < 4; ++i) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (IsValid(nx, ny, grid.Length, grid[0].Length) && !visited[nx][ny] && grid[nx][ny] > 0) {
        fish += DFS(nx, ny, grid);
      }
    }

    return fish;
  }

  public int FindMaxFish(int[][] grid) {
    int n = grid.Length;
    int m = grid[0].Length;
    visited = new bool[n][];
    for (int i = 0; i < n; ++i) {
      visited[i] = new bool[m];
    }

    int maxFish = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] > 0) {
          maxFish = Math.Max(maxFish, DFS(i, j, grid));
        }
      }
    }

    return maxFish;
  }
}