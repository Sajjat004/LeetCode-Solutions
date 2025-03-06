class Solution {
public:
  vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    int n = grid.size();
    vector<int> frequency(n * n + 1, 0);
    
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        frequency[grid[i][j]]++;
      }
    }

    int missing = 0, repeated = 0;
    for (int i = 1; i <= n * n; ++i) {
      if (frequency[i] == 0) missing = i;
      if (frequency[i] == 2) repeated = i;
    }

    return {repeated, missing};
  }
};