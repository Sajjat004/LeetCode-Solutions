public class Solution {
  public IList<int> EventualSafeNodes(int[][] graph) {
    int n = graph.Length;
    int[] inDegree = new int[n];
    List<List<int>> adj = new List<List<int>>();
    for (int i = 0; i < n; ++i) {
      adj.Add(new List<int>());
    }

    for (int i = 0; i < n; ++i) {
      foreach (int node in graph[i]) {
        adj[node].Add(i);
        inDegree[i]++;
      }
    }

    Queue<int> q = new Queue<int>();
    for (int i = 0; i < n; ++i) {
      if (inDegree[i] == 0) {
        q.Enqueue(i);
      }
    }

    bool[] safe = new bool[n];
    while (q.Count > 0) {
      int node = q.Dequeue();
      safe[node] = true;
      foreach (int neighbor in adj[node]) {
        inDegree[neighbor]--;
        if (inDegree[neighbor] == 0) {
          q.Enqueue(neighbor);
        }
      }
    }

    List<int> safeNodes = new List<int>();
    for (int i = 0; i < n; ++i) {
      if (safe[i]) {
        safeNodes.Add(i);
      }
    }

    return safeNodes;
  }
}