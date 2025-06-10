class Solution {
  void findComponent(int node, vector<int>& visited, vector<vector<int>>& graph, vector<int>& component) {
    visited[node] = 1;
    component.push_back(node);
    for (int neighbor : graph[node]) {
      if (!visited[neighbor]) {
        findComponent(neighbor, visited, graph, component);
      }
    }
  }

public:
  string smallestEquivalentString(string s1, string s2, string baseStr) {
    int n = s1.size();
    vector<vector<int>> graph(26, vector<int>());
    for (int i = 0; i < n; ++i) {
      int u = s1[i] - 'a';
      int v = s2[i] - 'a';
      if (u == v) continue;
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    vector<int> visited(26, 0);
    vector<int> smallestChar(26, 0);
    for (int i = 0; i < 26; ++i) {
      if (!visited[i]) {
        vector<int> component;
        findComponent(i, visited, graph, component);
        char minChar = 'z' + 1;
        for (int node : component) {
          minChar = min(minChar, (char)(node + 'a'));
        }
        for (int node : component) {
          smallestChar[node] = minChar - 'a';
        }
      }
    }

    string result;
    for (char c : baseStr) {
      int index = c - 'a';
      result += (char)(smallestChar[index] + 'a');
    }

    return result;
  }
};