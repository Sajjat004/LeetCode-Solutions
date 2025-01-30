public class Solution {
  public int MagnificentSets(int n, int[][] edges) {
    var adjList = new List<int>[n + 1];
    for (int i = 0; i <= n; i++) {
      adjList[i] = new List<int>();
    }
    foreach (var edge in edges) {
      adjList[edge[0]].Add(edge[1]);
      adjList[edge[1]].Add(edge[0]);
    }

    // Check if the graph is bipartite
    var colors = new int[n + 1];
    Array.Fill(colors, -1);
    for (int node = 1; node <= n; node++) {
      if (colors[node] == -1) {
        colors[node] = 0;
        if (!IsBipartite(node, adjList, colors)) {
          return -1;
        }
      }
    }

    // Get the longest shortest path from a node
    int[] distances = new int[n + 1];
    for (int node = 1; node <= n; node++) {
      distances[node] = GetLongestShortestPath(node, adjList, n);
    }

    bool[] visited = new bool[n + 1];
    int maxNumberOfGroups = 0;
    for (int node = 1; node <= n; node++) {
      if (!visited[node]) {
        maxNumberOfGroups += GetNumberOfGroupsForConnectedComponent(node, adjList, distances, visited);
      }
    }

    return maxNumberOfGroups;
  }

  // Check if the graph is bipartite
  private bool IsBipartite(int node, List<int>[] adjList, int[] colors) {
    foreach (var neighbor in adjList[node]) {
      if (colors[neighbor] == colors[node]) {
        return false;
      }
      if (colors[neighbor] == -1) {
        colors[neighbor] = 1 - colors[node];

        if (!IsBipartite(neighbor, adjList, colors)) {
          return false;
        }
      }
    }

    return true;
  }

  // Get the longest shortest path from a node
  private int GetLongestShortestPath(int node, List<int>[] adjList, int n) {
    bool[] visited = new bool[n + 1];
    Queue<int> nodesQueue = new Queue<int>();

    nodesQueue.Enqueue(node);
    visited[node] = true;
    int distance = 0;

    while (nodesQueue.Count > 0) {
      int layerSize = nodesQueue.Count;
      for (int i = 0; i < layerSize; i++) {
        int currentNode = nodesQueue.Dequeue();
        foreach (var neighbor in adjList[currentNode]) {
          if (!visited[neighbor]) {
            visited[neighbor] = true;
            nodesQueue.Enqueue(neighbor);
          }
        }
      }

      distance++;
    }

    return distance;
  }

  // Get the number of groups for a connected component
  private int GetNumberOfGroupsForConnectedComponent(int node, List<int>[] adjList, int[] distances, bool[] visited) {
    visited[node] = true;
    int maxNumberOfGroups = distances[node];

    foreach (var neighbor in adjList[node]) {
      if (!visited[neighbor]) {
        maxNumberOfGroups = Math.Max(maxNumberOfGroups, GetNumberOfGroupsForConnectedComponent(neighbor, adjList, distances, visited));
      }
    }

    return maxNumberOfGroups;
  }
}