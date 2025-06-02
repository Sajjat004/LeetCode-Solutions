class Solution {
  vector<vector<int>> getSnakesAndLaddersBoard(int n) {
    vector<vector<int>> board(n, vector<int>(n, -1));
    int num = 1;
    bool leftToRight = true;

    for (int i = n - 1; i >= 0; --i) {
      if (leftToRight) {
        for (int j = 0; j < n; ++j) {
          board[i][j] = num++;
        }
      } else {
        for (int j = n - 1; j >= 0; --j) {
          board[i][j] = num++;
        }
      }
      leftToRight = !leftToRight;
    }

    return board;
  }
public:
  int snakesAndLadders(vector<vector<int>>& board) {
    int n = board.size();
    vector<vector<int>> grid = getSnakesAndLaddersBoard(n);
    vector<pair<int, int>> cellToBoard(n * n + 1);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        int cellNumber = grid[i][j];
        cellToBoard[cellNumber] = {i, j};
      }
    }

    vector<vector<int>> graph((n * n) + 1);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        int currCell = grid[i][j];
        for (int diceRoll = 1; diceRoll <= 6; ++diceRoll) {
          int nextCell = currCell + diceRoll;
          if (nextCell > n * n) continue;
          auto [nextRow, nextCol] = cellToBoard[nextCell];
          if (board[nextRow][nextCol] != -1) {
            nextCell = board[nextRow][nextCol];
          }
          graph[currCell].push_back(nextCell);
        }
      }
    }

    vector<int> distance((n * n) + 1, -1);
    queue<int> q;
    q.push(1);
    distance[1] = 0;
    while (!q.empty()) {
      int current = q.front();
      q.pop();

      for (int neighbor : graph[current]) {
        if (distance[neighbor] == -1) {
          distance[neighbor] = distance[current] + 1;
          q.push(neighbor);
        }
      }
    }

    return distance[n * n];
  }
};