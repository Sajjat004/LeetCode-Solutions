class Solution {
public:
  int countServers(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> markAsConnected(n, vector<bool>(m, false));

    for (int i = 0; i < n; ++i) {
      int serversInRow = 0;
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == 1) serversInRow++;
      }

      if (serversInRow > 1) {
        for (int j = 0; j < m; ++j) {
          if (grid[i][j] == 1) markAsConnected[i][j] = true;
        }
      }
    }

    for (int j = 0; j < m; ++j) {
      int serversInColumn = 0;
      for (int i = 0; i < n; ++i) {
        if (grid[i][j] == 1) serversInColumn++;
      }

      if (serversInColumn > 1) {
        for (int i = 0; i < n; ++i) {
          if (grid[i][j] == 1) markAsConnected[i][j] = true;
        }
      }
    }

    int connectedServers = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (markAsConnected[i][j]) connectedServers++;
      }
    }

    return connectedServers;
  }
};