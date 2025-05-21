class Solution {
public:
  void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<bool> zeroRow(n, false);
    vector<bool> zeroCol(m, false);

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (matrix[i][j] == 0) {
          zeroRow[i] = true;
          zeroCol[j] = true;
        }
      }
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (zeroRow[i] || zeroCol[j]) {
          matrix[i][j] = 0;
        }
      }
    }
  }
};