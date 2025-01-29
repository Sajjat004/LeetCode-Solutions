public class Solution {
  private int cycleStart = -1;

  private void DFS(int node, List<int>[] adjList, bool[] visited, int[] parent) {
    visited[node] = true;

    foreach (var neighbor in adjList[node]) {
      if (cycleStart != -1) return;

      if (!visited[neighbor]) {
        parent[neighbor] = node;
        DFS(neighbor, adjList, visited, parent);
      } else if (parent[node] != neighbor) {
        cycleStart = neighbor;
        parent[neighbor] = node;

        return;
      }
    }
  }

  public int[] FindRedundantConnection(int[][] edges) {
    int n = edges.Length;

    List<int>[] adjList = new List<int>[n + 1];
    for (int i = 0; i < n + 1; ++i) adjList[i] = new List<int>();
    foreach (var edge in edges) {
      adjList[edge[0]].Add(edge[1]);
      adjList[edge[1]].Add(edge[0]);
    }

    bool[] visited = new bool[n + 1];
    int[] parent = new int[n + 1];
    DFS(1, adjList, visited, parent);

    Dictionary<int, int> cycleNodes = new Dictionary<int, int>();
    int node = cycleStart;
    do {
      cycleNodes[node] = 1;
      node = parent[node];
    } while (node != cycleStart);

    for (int i = n - 1; i >= 0; --i) {
      if (cycleNodes.ContainsKey(edges[i][0]) && cycleNodes.ContainsKey(edges[i][1])) {
        return edges[i];
      }
    }

    return new int[0];
  }
}