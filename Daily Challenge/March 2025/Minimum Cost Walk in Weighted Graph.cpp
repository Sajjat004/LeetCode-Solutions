class Solution {
public:
  vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
    vector<vector<pair<int, int>>> adjList(n);
    for (auto& edge : edges) {
      adjList[edge[0]].push_back({edge[1], edge[2]});
      adjList[edge[1]].push_back({edge[0], edge[2]});
    }

    vector<int> visited(n, false);
    vector<int> components(n, -1);
    vector<int> componentCost;
    int componentId = 0;

    for (int node = 0; node < n; ++node) {
      if (!visited[node]) {
        componentCost.push_back(getComponentCost(node, adjList, visited, components, componentId));
        ++componentId;
      }
    }

    vector<int> result;
    for (auto& query : queries) {
      int source = query[0];
      int destination = query[1];
      

      if (components[source] == components[destination]) {
        result.push_back(componentCost[components[source]]);
      } else {
        result.push_back(-1);
      }
    }

    return result;
  }

private:
  int getComponentCost(int source, vector<vector<pair<int, int>>>& adjList, vector<int>& visited, vector<int>& components, int componentId) {
    int componentCost = INT_MAX;

    queue<int> nodesQueue;
    nodesQueue.push(source);
    visited[source] = true;

    while (!nodesQueue.empty()) {
      int node = nodesQueue.front();
      nodesQueue.pop();
      components[node] = componentId;

      for (auto& [neighbour, weight] : adjList[node]) {
        componentCost &= weight;

        if (!visited[neighbour]) {
          visited[neighbour] = true;
          nodesQueue.push(neighbour);
        }
      }
    }

    return componentCost;
  }
};