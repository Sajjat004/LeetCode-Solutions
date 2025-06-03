
struct State {
  int x, y, energyLeft, mask, moves;
  State(int x, int y, int energyLeft, int mask, int moves)
      : x(x), y(y), energyLeft(energyLeft), mask(mask), moves(moves) {}
};

class Solution {
public:
  int minMoves(vector<string>& classroom, int energy) {
    int n = classroom.size();
    int m = classroom[0].size();

    map<pair<int, int>, int> littersIndex;
    int cntLitters = 0;
    pair<int, int> start;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (classroom[i][j] == 'L') {
          littersIndex[{i, j}] = cntLitters++;
        } else if (classroom[i][j] == 'S') {
          start = {i, j};
        }
      }
    }

    bool visited[20][20][1 << cntLitters][51];
    memset(visited, false, sizeof(visited));

    queue<State> q;
    q.push(State(start.first, start.second, energy, 0, 0));
    visited[start.first][start.second][0][energy] = true;

    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    while (!q.empty()) {
      State curr = q.front();
      q.pop();

      if (curr.mask == (1 << cntLitters) - 1) return curr.moves;
      if (curr.energyLeft == 0) continue;

      for (const auto& dir : directions) {
        int newX = curr.x + dir[0];
        int newY = curr.y + dir[1];

        if (newX < 0 || newX >= n || newY < 0 || newY >= m || classroom[newX][newY] == 'X') continue;
        int newMask = curr.mask;
        if (classroom[newX][newY] == 'L') newMask |= (1 << littersIndex[{newX, newY}]);
        int newEnergy = curr.energyLeft - 1;
        if (classroom[newX][newY] == 'R') newEnergy = energy;

        if (!visited[newX][newY][newMask][newEnergy]) {
          visited[newX][newY][newMask][newEnergy] = true;
          q.push(State(newX, newY, newEnergy, newMask, curr.moves + 1));
        }
      }
    }

    return -1;
  }
};