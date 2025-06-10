class Solution {
  int componentSize;
  bool isCycle;
  void dfs(int node, int par, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    componentSize++;

    for (int neighbor : graph[node]) {
      if (!visited[neighbor]) {
        dfs(neighbor, node, graph, visited);
      } else if (neighbor != par) {
        isCycle = true;
      }
    }
  }
public:
  long long maxScore(int n, vector<vector<int>>& edges) {
    vector<vector<int>> graph(n);

    for (const auto& edge : edges) {
      int u = edge[0];
      int v = edge[1];
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    vector<bool> visited(n, 0);
    vector<pair<bool, int>> componentInfo;

    long long maxScore = 0;
    for (int node = 0; node < n; ++node) {
      if (!visited[node]) {
        componentSize = 0;
        isCycle = false;
        dfs(node, -1, graph, visited);

        componentInfo.push_back({isCycle, componentSize});
      }
    }

    sort(componentInfo.begin(), componentInfo.end());
    int value = 1;
    
    for (auto& x : componentInfo) {
      int componentCount = x.second;
      bool isCycleExist = x.first;

      vector<int> component(componentCount);
      int left = 0, right = componentCount - 1;
      while (left <= right) {
        component[left] = value++;
        if (left < right) component[right] = value++;
        left++;
        right--;
      }

      for (int i = 1; i < componentCount; ++i) {
        maxScore += 1LL * component[i] * component[i - 1];
      }
      if (isCycleExist) {
        maxScore += 1LL * component[0] * component[componentCount - 1];
      }
    }

    return maxScore;
  }
};