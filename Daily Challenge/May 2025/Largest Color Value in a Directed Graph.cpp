class Solution {
  bool isCyclic(int n, const vector<vector<int>>& edges) {
    vector<int> inDegree(n, 0);
    vector<vector<int>> graph(n);
    for (const auto& edge : edges) {
      int u = edge[0], v = edge[1];
      graph[u].push_back(v);
      inDegree[v]++;
    }

    queue<int> q;
    for (int i = 0; i < n; ++i) {
      if (inDegree[i] == 0) {
        q.push(i);
      }
    }

    int visitedCount = 0;
    while (!q.empty()) {
      int node = q.front();
      q.pop();
      visitedCount++;
      for (int neighbor : graph[node]) {
        inDegree[neighbor]--;
        if (inDegree[neighbor] == 0) {
          q.push(neighbor);
        }
      }
    }

    return visitedCount != n;
  }

  int dfs(int node, const vector<vector<int>>& graph, vector<int>& dp, vector<bool>& visited, const string& colors, char color) {
    if (visited[node]) {
      return dp[node]; // Return the cached result
    }
    visited[node] = true;

    int maxColorValue = 0;
    for (int neighbor : graph[node]) {
      maxColorValue = max(maxColorValue, dfs(neighbor, graph, dp, visited, colors, color));
    }

    dp[node] = maxColorValue + (colors[node] == color); // Convert color to a value
    return dp[node];
  }

public:
  int largestPathValue(string colors, vector<vector<int>>& edges) {
    if (isCyclic(colors.size(), edges)) {
      return -1; // If the graph has a cycle, return -1
    }

    int n = colors.size();
    vector<vector<int>> graph(n);
    for (const auto& edge : edges) {
      graph[edge[0]].push_back(edge[1]);
    }

    int ans = 0;

    for (char color = 'a'; color <= 'z'; ++color) {
      vector<int> dp(n, 0);
      vector<bool> visited(n, false);
      for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
          ans = max(ans, dfs(i, graph, dp, visited, colors, color));
        }
      }
    }

    return ans;
  }
};