class Solution {
  void findDistance(int start, vector<vector<int>>& graph, vector<int>& distance) {
    queue<int> q;
    q.push(start);
    distance[start] = 0;

    while (!q.empty()) {
      int node = q.front();
      q.pop();

      for (int neighbor : graph[node]) {
        if (distance[neighbor] == -1) {
          distance[neighbor] = distance[node] + 1;
          q.push(neighbor);
        }
      }
    }
  }

public:
  int closestMeetingNode(vector<int>& edges, int node1, int node2) {
    int n = edges.size();
    vector<vector<int>> graph(n);
    for (int i = 0; i < n; ++i) {
      if (edges[i] != -1) {
        graph[i].push_back(edges[i]);
      }
    }

    vector<int> distance1(n, -1);
    vector<int> distance2(n, -1);
    findDistance(node1, graph, distance1);
    findDistance(node2, graph, distance2);

    int minDistance = INT_MAX;
    int closestNode = -1;
    for (int i = 0; i < n; ++i) {
      if (distance1[i] != -1 && distance2[i] != -1) {
        int maxDistance = max(distance1[i], distance2[i]);
        if (maxDistance < minDistance) {
          minDistance = maxDistance;
          closestNode = i;
        }
      }
    }
    
    return closestNode;
  }
};