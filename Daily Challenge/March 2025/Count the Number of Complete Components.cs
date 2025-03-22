public class Solution {
  public int CountCompleteComponents(int n, int[][] edges) {
    var adjList = new List<int>[n];
    for (int i = 0; i < n; i++) {
      adjList[i] = new List<int>();
    }
    foreach (var edge in edges) {
      adjList[edge[0]].Add(edge[1]);
      adjList[edge[1]].Add(edge[0]);
    }

    var visited = new bool[n];
    var components = new List<int>();
    int completeComponets = 0;

    for (int i = 0; i < n; ++i) {
      if (!visited[i]) {
        GetConnetedComponents(i, adjList, visited, components);
        bool isComplete = true;

        foreach (var node in components) {
          if (adjList[node].Count < (components.Count - 1)) {
            isComplete = false;
            break;
          }
        }

        if (isComplete) {
          completeComponets++;
        }
        components.Clear();
      }
    }

    return completeComponets;
  }

  private void GetConnetedComponents(int node, List<int>[] adjList, bool[] visited, List<int> components) {
    if (visited[node]) {
      return;
    }

    visited[node] = true;
    components.Add(node);

    foreach (var neighbor in adjList[node]) {
      GetConnetedComponents(neighbor, adjList, visited, components);
    }
  }
}