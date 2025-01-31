class Solution {
public:
  int largestIsland(vector<vector<int>>& grid) {
    int n = grid.size();
    unordered_map<int, int> islandSizes;
    int islandId = 2;

    for (int currentRow = 0; currentRow < n; ++currentRow) {
      for (int currentColumn = 0; currentColumn < n; ++currentColumn) {
        if (grid[currentRow][currentColumn] == 1) {
          islandSizes[islandId] = exploreIsland(grid, islandId, currentRow, currentColumn);
          ++islandId;
        }
      }
    }

    if (islandSizes.empty()) return 1;

    if (islandSizes.size() == 1) {
      --islandId;
      return (islandSizes[islandId] == n * n) ? islandSizes[islandId] : islandSizes[islandId] + 1;
    }

    int maxIslandSize = 1;
    for (int currentRow = 0; currentRow < n; ++currentRow) {
      for (int currentColumn = 0; currentColumn < n; ++currentColumn) {
        if (grid[currentRow][currentColumn] == 0) {
          int currentIslandSize = 1;
          unordered_set<int> neighboringIslands;

          if (!isOutOfBounds(currentRow + 1, currentColumn, n) && grid[currentRow + 1][currentColumn] > 1) {
            neighboringIslands.insert(grid[currentRow + 1][currentColumn]);
          }

          if (!isOutOfBounds(currentRow - 1, currentColumn, n) && grid[currentRow - 1][currentColumn] > 1) {
            neighboringIslands.insert(grid[currentRow - 1][currentColumn]);
          }

          if (!isOutOfBounds(currentRow, currentColumn + 1, n) && grid[currentRow][currentColumn + 1] > 1) {
            neighboringIslands.insert(grid[currentRow][currentColumn + 1]);
          }

          if (!isOutOfBounds(currentRow, currentColumn - 1, n) && grid[currentRow][currentColumn - 1] > 1) {
            neighboringIslands.insert(grid[currentRow][currentColumn - 1]);
          }

          for (int islandId : neighboringIslands) {
            currentIslandSize += islandSizes[islandId];
          }

          maxIslandSize = max(maxIslandSize, currentIslandSize);
        }
      }
    }

    return maxIslandSize;
  }

private:

  int exploreIsland(vector<vector<int>>& grid, int islandId, int currentRow, int currentColumn) {
    if (isOutOfBounds(currentRow, currentColumn, grid.size()) || grid[currentRow][currentColumn] != 1) return 0;

    grid[currentRow][currentColumn] = islandId;

    return 1 + exploreIsland(grid, islandId, currentRow + 1, currentColumn) +
               exploreIsland(grid, islandId, currentRow - 1, currentColumn) +
               exploreIsland(grid, islandId, currentRow, currentColumn + 1) +
               exploreIsland(grid, islandId, currentRow, currentColumn - 1);
  }

  bool isOutOfBounds(int currentRow, int currentColumn, int n) {
    return currentRow < 0 || currentRow >= n || currentColumn < 0 || currentColumn >= n;
  }
};