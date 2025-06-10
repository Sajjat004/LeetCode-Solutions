class Solution {
public:
  bool canPartitionGrid(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    long long totalSum = 0;

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        totalSum += grid[i][j];
      }
    }

    if (totalSum % 2 != 0) return false;

    long long subSum = 0;
    for (int i = 0; i < (n - 1); ++i) {
      for (int j = 0; j < m; ++j) {
        subSum += grid[i][j];
      }
      if (subSum == totalSum / 2) {
        return true;
      }
    }

    subSum = 0;
    for (int j = 0; j < (m - 1); ++j) {
      for (int i = 0; i < n; ++i) {
        subSum += grid[i][j];
      }
      if (subSum == totalSum / 2) {
        return true;
      }
    }

    return false;
  }
};