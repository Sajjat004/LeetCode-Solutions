// Challenge Date: 01 Sep, 2024
class Solution {
public:
  vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {

    vector<vector<int>> ans;
    if ((n * m) != original.size()) return ans;
    ans.resize(m, vector<int>(n, 0));
    int index = 0;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        ans[i][j] = original[index++];
      }
    }

    return ans;
  }
};