class Solution {
  const int maxValue = 100000;
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

    // calculate row and column sum
    vector<long long> rowSum(n + 1, 0);
    vector<long long> colSum(m + 1, 0);
    for (int i = 0; i < n; ++i) {
      long long sum = 0;
      for (int j = 0; j < m; ++j) sum += grid[i][j];
      rowSum[i] = sum + (i > 0 ? rowSum[i - 1] : 0);
    }
    for (int j = 0; j < m; ++j) {
      long long sum = 0;
      for (int i = 0; i < n; ++i) sum += grid[i][j];
      colSum[j] = sum + (j > 0 ? colSum[j - 1] : 0);
    }

    vector<int> rowValueMinIndex(100005, n);
    vector<int> rowValueMaxIndex(100005, -1);
    vector<int> colValueMinIndex(100005, m);
    vector<int> colValueMaxIndex(100005, -1);
    // calculate min and max index for each value
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        rowValueMinIndex[grid[i][j]] = min(rowValueMinIndex[grid[i][j]], i);
        rowValueMaxIndex[grid[i][j]] = max(rowValueMaxIndex[grid[i][j]], i);
        colValueMinIndex[grid[i][j]] = min(colValueMinIndex[grid[i][j]], j);
        colValueMaxIndex[grid[i][j]] = max(colValueMaxIndex[grid[i][j]], j);
      }
    }

    // horizontal cut
    for (int i = 0; i < (n - 1); ++i) {
      long long upperSum = rowSum[i];
      long long lowerSum = totalSum - upperSum;
      long long diff = abs(upperSum - lowerSum);
      if (diff == 0) return true;

      if (diff <= maxValue) {
        if (upperSum > lowerSum and (grid[0][0] == diff or grid[0][m - 1] == diff or grid[i][0] == diff or grid[i][m - 1] == diff)) return true;
        if (lowerSum > upperSum and (grid[n - 1][0] == diff or grid[n - 1][m - 1] == diff or grid[i + 1][0] == diff or grid[i + 1][m - 1] == diff)) return true;
        if (upperSum > lowerSum and i > 1 and m > 1 and rowValueMinIndex[diff] <= i) return true;
        if (lowerSum > upperSum and i < (n - 2) and m > 1 and rowValueMaxIndex[diff] >= (i + 1)) return true;
      }
    }

    // vertical cut
    for (int j = 0; j < (m - 1); ++j) {
      long long leftSum = colSum[j];
      long long rightSum = totalSum - leftSum;
      long long diff = abs(leftSum - rightSum);
      if (diff == 0) return true;

      if (diff <= maxValue) {
        if (leftSum > rightSum and (grid[0][0] == diff or grid[n - 1][0] == diff or grid[0][j] == diff or grid[n - 1][j] == diff)) return true;
        if (rightSum > leftSum and (grid[0][m - 1] == diff or grid[n - 1][m - 1] == diff or grid[0][j + 1] == diff or grid[n - 1][j + 1] == diff)) return true;
        if (leftSum > rightSum and j > 1 and n > 1 and colValueMinIndex[diff] <= j) return true;
        if (rightSum > leftSum and j < (m - 2) and n > 1 and colValueMaxIndex[diff] >= (j + 1)) return true;
      }
    }

    return false;
  }
};