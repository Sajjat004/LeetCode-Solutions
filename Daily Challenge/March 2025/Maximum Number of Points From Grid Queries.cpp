class Solution {
public:
  vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
    int rows = grid.size(), cols = grid[0].size();

    vector<int> result(queries.size(), 0);
    vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    vector<pair<int, int>> sortedQueries(queries.size());
    for (int i = 0; i < queries.size(); ++i) {
      sortedQueries[i] = {queries[i], i};
    }
    sort(sortedQueries.begin(), sortedQueries.end());

    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> minHeap;
    int totalPoints = 0;
    minHeap.push({grid[0][0], {0, 0}});
    visited[0][0] = true;

    for (auto [queryValue, queryIndex] : sortedQueries) {
      while (!minHeap.empty() && minHeap.top().first < queryValue) {
        auto [value, position] = minHeap.top();
        minHeap.pop();
        totalPoints++;

        for (auto [dx, dy] : DIRECTIONS) {
          int newRow = position.first + dx;
          int newCol = position.second + dy;
          if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && !visited[newRow][newCol]) {
            visited[newRow][newCol] = true;
            minHeap.push({grid[newRow][newCol], {newRow, newCol}});
          }
        }
      }
      result[queryIndex] = totalPoints;
    }

    return result;
  }
};