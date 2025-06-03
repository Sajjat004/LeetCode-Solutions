class Solution {
public:
  vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> ans;

    for (int i = 0; (i + k - 1) < n; ++i) {
      vector<int> rowAns;
      for (int j = 0; (j + k - 1) < m; ++j) {
        vector<int> uniqueValues;
        for (int x = i; x < i + k; ++x) {
          for (int y = j; y < j + k; ++y) {
            uniqueValues.push_back(grid[x][y]);
          }
        }
        sort(uniqueValues.begin(), uniqueValues.end());
        uniqueValues.erase(unique(uniqueValues.begin(), uniqueValues.end()), uniqueValues.end());

        if (uniqueValues.size() < 2) {
          rowAns.push_back(0);
        } else {
          int minDiff = INT_MAX;
          for (int x = 1; x < uniqueValues.size(); ++x) {
            minDiff = min(minDiff, uniqueValues[x] - uniqueValues[x - 1]);
          }
          rowAns.push_back(minDiff);
        }
      }

      ans.push_back(rowAns);
    }

    return ans;
  }
};