class Solution {
public:
  vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> inDegree(n, 0);
    vector<vector<int>> adj(n);

    for (int i = 0; i < n; ++i) {
      for (int node : graph[i]) {
        adj[node].push_back(i);
        inDegree[i]++;
      }
    }

    queue<int> q;
    for (int i = 0; i < n; ++i) {
      if (inDegree[i] == 0) {
        q.push(i);
      }
    }

    vector<bool> safe(n, false);
    while (!q.empty()) {
      int node = q.front();
      q.pop();
      safe[node] = true;
      for (int neighbor : adj[node]) {
        inDegree[neighbor]--;
        if (inDegree[neighbor] == 0) {
          q.push(neighbor);
        }
      }
    }

    vector<int> safeNodes;
    for (int i = 0; i < n; ++i) {
      if (safe[i]) {
        safeNodes.push_back(i);
      }
    }

    return safeNodes;
  }
};