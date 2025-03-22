class Solution {
public:
  int countCompleteComponents(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adjList(n);
    for (auto& edge : edges) {
      adjList[edge[0]].push_back(edge[1]);
      adjList[edge[1]].push_back(edge[0]);
    }

    vector<bool> visited(n, false);
    vector<int> componnets;

    int completeComponents = 0;
    for (int i = 0; i < n; ++i) {
      if (!visited[i]) {
        getConnectedComponet(i, adjList, visited, componnets);

        bool isCompleteComponent = true;
        for (auto& node : componnets) {
          if (adjList[node].size() < (componnets.size() - 1)) {
            isCompleteComponent = false;
            break;
          }
        }

        if (isCompleteComponent) {
          ++completeComponents;
        }

        componnets.clear();
      }
    }

    return completeComponents;
  }

private:
  void getConnectedComponet(int node, vector<vector<int>>& adjList, vector<bool>& visited, vector<int>& componnets) {
    visited[node] = true;
    componnets.push_back(node);

    for (auto& neighbor : adjList[node]) {
      if (!visited[neighbor]) {
        getConnectedComponet(neighbor, adjList, visited, componnets);
      }
    }
  }
};