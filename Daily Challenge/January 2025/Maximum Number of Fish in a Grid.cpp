class Solution {

  vector<vector<bool>> visited;
  vector<int> dx = {0, 0, 1, -1};
  vector<int> dy = {1, -1, 0, 0};

  bool isValid(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
  }

  int dfs(int x, int y, vector<vector<int>>& grid) {
    visited[x][y] = 1;

    int fish = grid[x][y];
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (isValid(nx, ny, grid.size(), grid[0].size()) && !visited[nx][ny] && grid[nx][ny] > 0) {
        fish += dfs(nx, ny, grid);
      }
    }

    return fish;
  }

public:
  int findMaxFish(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    visited = vector<vector<bool>>(n, vector<bool>(m, 0));

    int maxFish = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (grid[i][j] > 0 && !visited[i][j]) {
          maxFish = max(maxFish, dfs(i, j, grid));
        }
      }
    }

    return maxFish;
  }
};