public class Solution {
  private int[] rowDirections = new int[] { -1, 1, 0, 0 };
  private int[] columnDirections = new int[] { 0, 0, -1, 1 };


  public int LargestIsland(int[][] grid) {
    int n = grid.Length;
    
    Dictionary<int, int> islandSizes = new Dictionary<int, int>();
    int islandId = 2;

    for (int currentRow = 0; currentRow < n; currentRow++) {
      for (int currentColumn = 0; currentColumn < n; currentColumn++) {
        if (grid[currentRow][currentColumn] == 1) {
          int islandSize = ExploreIsland(grid, islandId, currentRow, currentColumn);
          islandSizes.Add(islandId, islandSize);
          islandId++;
        }
      }
    }

    if (islandSizes.Count == 0) return 1;
    if (islandSizes.Count == 1) {
      islandId--;
      return (islandSizes[islandId] == n * n) ? islandSizes[islandId] : islandSizes[islandId] + 1;
    }

    int maxIslandSize = 0;
    for (int currentRow = 0; currentRow < n; currentRow++) {
      for (int currentColumn = 0; currentColumn < n; currentColumn++) {
        if (grid[currentRow][currentColumn] == 0) {
          HashSet<int> connectedIslands = new HashSet<int>();

          for (int i = 0; i < rowDirections.Length; i++) {
            int newRow = currentRow + rowDirections[i];
            int newColumn = currentColumn + columnDirections[i];

            if (IsInGrid(grid, newRow, newColumn) && grid[newRow][newColumn] != 0) {
              connectedIslands.Add(grid[newRow][newColumn]);
            }
          }

          int currentIslandSize = 1;
          foreach (int island in connectedIslands) {
            currentIslandSize += islandSizes[island];
          }

          maxIslandSize = Math.Max(maxIslandSize, currentIslandSize);
        }
      }
    }

    return maxIslandSize;
  }

  private int ExploreIsland(int[][] grid, int islandId, int currentRow, int currentColumn) {
    if (!IsInGrid(grid, currentRow, currentColumn) || grid[currentRow][currentColumn] != 1) return 0;

    grid[currentRow][currentColumn] = islandId;
    int islandSize = 1;

    for (int i = 0; i < rowDirections.Length; i++) {
      int newRow = currentRow + rowDirections[i];
      int newColumn = currentColumn + columnDirections[i];

      islandSize += ExploreIsland(grid, islandId, newRow, newColumn);
    }

    return islandSize;
  }

  private bool IsInGrid(int[][] grid, int row, int column) {
    return row >= 0 && row < grid.Length && column >= 0 && column < grid[0].Length;
  }
}