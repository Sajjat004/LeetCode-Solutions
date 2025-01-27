class Solution {
  map<pair<int, int>, bool> dp;
  vector<bool> isVisited;
  int prerequisite = 0;

  void dfs(int node, vector<vector<int>>& graph) {
    isVisited[node] = true;
    dp[{prerequisite, node}] = true;
  
    for (int child : graph[node]) {
      if (!isVisited[child]) {
        dfs(child, graph);
      }
    }
  }

public:
  vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
    dp.clear();
    isVisited.assign(numCourses, false);
    vector<vector<int>> graph(numCourses);

    for (auto& p : prerequisites) {
      graph[p[0]].push_back(p[1]);
    }

    for (int i = 0; i < numCourses; i++) {
      prerequisite = i;
      dfs(i, graph);
      isVisited.assign(numCourses, false);
    }

    vector<bool> result;
    for (auto& q : queries) {
      result.push_back(dp[{q[0], q[1]}]);
    }

    return result;

  }
};