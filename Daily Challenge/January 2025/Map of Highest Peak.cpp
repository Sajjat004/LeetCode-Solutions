class Solution {
public:
  vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
    int n = isWater.size();
    int m = isWater[0].size();
    queue<pair<int, int>> q;
    vector<vector<int>> height(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (isWater[i][j] == 1) {
          q.push({i, j});
          height[i][j] = 0;
        }
      }
    }

    auto isValid = [&](int x, int y) {
      return x >= 0 && x < n && y >= 0 && y < m;
    };

    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};

    while (!q.empty()) {
      auto [x, y] = q.front();
      q.pop();

      for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (isValid(nx, ny) && height[nx][ny] == -1) {
          height[nx][ny] = height[x][y] + 1;
          q.push({nx, ny});
        }
      }
    }

    return height;
  }
};