class Solution {
public:
  int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
    map<int, pair<int, int>> MAP;
    int n = mat.size();
    int m = mat[0].size();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        MAP[mat[i][j]] = {i + 1, j + 1};
      }
    }
    vector<int> row(n + 2, 0), col(m + 2, 0);
    int idx = 0;
    for (auto ii : arr) {
      auto x = MAP[ii];
      row[x.first]++;
      col[x.second]++;
      if (row[x.first] == m or col[x.second] == n) return idx;
      idx++;
    }
    return 0;
  }
};