class Solution {
private:
  int cycleStart = -1;

  void dfs(int node, vector<int> adjList[], vector<int>& parent, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : adjList[node]) {
      if (!visited[neighbor]) {
        parent[neighbor] = node;
        dfs(neighbor, adjList, parent, visited);
      } else if (neighbor != parent[node] && cycleStart == -1) {
        cycleStart = neighbor;
        parent[neighbor] = node;
      }
    }
  }

public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int n = edges.size();

    vector<int> adjList[n + 1];
    for (auto edge : edges) {
      adjList[edge[0]].push_back(edge[1]);
      adjList[edge[1]].push_back(edge[0]);
    }

    vector<int> parent(n + 1, -1);
    vector<bool> visited(n + 1, false);
    dfs(1, adjList, parent, visited);

    unordered_map<int, int> cycleNodes;
    int node = cycleStart;
    do {
      cycleNodes[node] = 1;
      node = parent[node];
    } while (node != cycleStart);

    for (int i = n - 1; i >= 0; i--) {
      if (cycleNodes[edges[i][0]] && cycleNodes[edges[i][1]]) {
        return edges[i];
      }
    }

    return {};
  }
};