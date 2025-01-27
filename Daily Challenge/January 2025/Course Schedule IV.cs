public class Solution {
  private Dictionary<(int, int), bool> _dp = new Dictionary<(int, int), bool>();
  private bool[] _isVisited;
  private int _prerequisite;

  private void DFS(int node, List<int>[] graph) {
    _isVisited[node] = true;
    _dp[(_prerequisite, node)] = true;

    foreach (var next in graph[node]) {
      if (!_isVisited[next]) {
        DFS(next, graph);
      }
    }
  }

  public IList<bool> CheckIfPrerequisite(int numCourses, int[][] prerequisites, int[][] queries) {
    _dp.Clear();
    _isVisited = new bool[numCourses];
    var graph = new List<int>[numCourses];
    for (int i = 0; i < numCourses; i++) {
      graph[i] = new List<int>();
    }

    foreach (var prerequisite in prerequisites) {
      graph[prerequisite[0]].Add(prerequisite[1]);
    }

    for (int i = 0; i < numCourses; i++) {
      _prerequisite = i;
      DFS(i, graph);
      Array.Fill(_isVisited, false);
    }

    var result = new List<bool>();
    foreach (var query in queries) {
      result.Add(_dp.GetValueOrDefault((query[0], query[1]), false));
    }

    return result;
  }
}