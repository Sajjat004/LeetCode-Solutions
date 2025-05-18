struct State {
  int x, y, dist;
  State(int x, int y, int dist) : x(x), y(y), dist(dist) {}

  bool operator<(const State& other) const {
    return dist > other.dist;
  }
};

class Solution {
  const int dx[4] = {1, -1, 0, 0};
  const int dy[4] = {0, 0, 1, -1};
public:
  int minMoves(vector<string>& matrix) {
    int n = matrix.size(), m = matrix[0].size();

    vector<vector<pair<int, int>>> teleports(26);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (matrix[i][j] >='A' && matrix[i][j] <= 'Z') {
          teleports[matrix[i][j] - 'A'].push_back({i, j});
        }
      }
    }
    vector<bool> visitedTeleport(26, false);

    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    priority_queue<State> pq;
    pq.push(State(0, 0, 0));
    dist[0][0] = 0;

    while (!pq.empty()) {
      State curr = pq.top();
      pq.pop();

      for (int i = 0; i < 4; ++i) {
        int newX = curr.x + dx[i];
        int newY = curr.y + dy[i];

        if (newX >= 0 && newX < n && newY >= 0 && newY < m && matrix[newX][newY] != '#') {
          int newDist = curr.dist + 1;
          if (newDist < dist[newX][newY]) {
            dist[newX][newY] = newDist;
            pq.push(State(newX, newY, newDist));
          }
        }
      }

      if (matrix[curr.x][curr.y] >= 'A' && matrix[curr.x][curr.y] <= 'Z' and !visitedTeleport[matrix[curr.x][curr.y] - 'A']) {
        visitedTeleport[matrix[curr.x][curr.y] - 'A'] = true;
        for (auto& teleport : teleports[matrix[curr.x][curr.y] - 'A']) {
          int newX = teleport.first;
          int newY = teleport.second;

          if (newX != curr.x || newY != curr.y) {
            int newDist = curr.dist;
            if (newDist < dist[newX][newY]) {
              dist[newX][newY] = newDist;
              pq.push(State(newX, newY, newDist));
            }
          }
        }
      }
    }

    int ans = dist[n - 1][m - 1];
    return ans == INT_MAX ? -1 : ans;
  }
};