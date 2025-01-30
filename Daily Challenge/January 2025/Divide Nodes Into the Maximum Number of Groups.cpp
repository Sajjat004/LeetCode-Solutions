class Solution {
public:
  int magnificentSets(int n, vector<vector<int>>& edges) {
    vector<vector<int>> adjList(n + 1);
    for (auto edge : edges) {
      adjList[edge[0]].push_back(edge[1]);
      adjList[edge[1]].push_back(edge[0]);
    }

    // Check if the graph is bipartite
    vector<int> color(n + 1, -1);
    for (int node = 1; node <= n; node++) {
      if (color[node] == -1) {
        color[node] = 0;
        if (!isBipartite(node, adjList, color)) {
          return -1;
        }
      }
    }

    // Get the longest shortest path from each node
    vector<int> distances(n + 1);
    for (int node = 1; node <= n; node++) {
      distances[node] = getLongestShortestPath(node, adjList, n);
    }

    vector<bool> visited(n + 1, false);
    int maxNumbersOfGroups = 0;
    for (int node = 1; node <= n; node++) {
      if (!visited[node]) {
        maxNumbersOfGroups += getNumberOfGroupsForConnectedComponent(node, adjList, distances, visited);
      }
    }

    return maxNumbersOfGroups;
  }

private:
  // Check if the graph is bipartite
  bool isBipartite(int node, vector<vector<int>>& adjList, vector<int>& color) {
    for (int neighbor : adjList[node]) {
      if (color[neighbor] == -1) {
        color[neighbor] = 1 - color[node];
        if (!isBipartite(neighbor, adjList, color)) {
          return false;
        }
      } else if (color[neighbor] == color[node]) {
        return false;
      }
    }

    return true;
  }

  // Get the longest shortest path from a node
  int getLongestShortestPath(int sourceNode, vector<vector<int>>& adjList, int n) {
    vector<int> visited(n + 1, false);
    queue<int> nodesQueue;

    nodesQueue.push(sourceNode);
    visited[sourceNode] = true;
    int distance = 0;

    while (!nodesQueue.empty()) {
      int layerSize = nodesQueue.size();
      for (int i = 0; i < layerSize; i++) {
        int node = nodesQueue.front();
        nodesQueue.pop();

        for (int neighbor : adjList[node]) {
          if (!visited[neighbor]) {
            nodesQueue.push(neighbor);
            visited[neighbor] = true;
          }
        }
      }

      distance++;
    }

    return distance;
  }

  // Get the maximum number of groups for a connected component
  int getNumberOfGroupsForConnectedComponent(int node, vector<vector<int>>& adjList, vector<int>& distances, vector<bool>& visited) {
    visited[node] = true;
    int maxNumbersOfGroups = distances[node];

    for (int neighbor : adjList[node]) {
      if (!visited[neighbor]) {
        maxNumbersOfGroups = max(maxNumbersOfGroups, getNumberOfGroupsForConnectedComponent(neighbor, adjList, distances, visited));
      }
    }

    return maxNumbersOfGroups;
  }
};