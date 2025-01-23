public class Solution {
  public int CountServers(int[][] grid) {
    int n = grid.Length;
    int m = grid[0].Length;
    bool[][] markAsConnected = new bool[n][];
    for (int i = 0; i < n; i++) {
      markAsConnected[i] = new bool[m];
    }

    for (int i = 0; i < n; ++i) {
      int countServersInRow = 0;
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == 1) {
          countServersInRow++;
        }
      }

      if (countServersInRow > 1) {
        for (int j = 0; j < m; ++j) {
          if (grid[i][j] == 1) {
            markAsConnected[i][j] = true;
          }
        }
      }
    }

    for (int j = 0; j < m; ++j) {
      int countServersInColumn = 0;
      for (int i = 0; i < n; ++i) {
        if (grid[i][j] == 1) {
          countServersInColumn++;
        }
      }

      if (countServersInColumn > 1) {
        for (int i = 0; i < n; ++i) {
          if (grid[i][j] == 1) {
            markAsConnected[i][j] = true;
          }
        }
      }
    }

    int countConnectedServers = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (markAsConnected[i][j]) {
          countConnectedServers++;
        }
      }
    }

    return countConnectedServers;
  }
}