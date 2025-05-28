class Solution {
  int countNodeWithMaxEdges(int node, int parent, vector<vector<int>>& tree, int maxEdge) {
    if (maxEdge == 0) return 1;
    int count = 1;
    for (int child : tree[node]) {
      if (child != parent) {
        count += countNodeWithMaxEdges(child, node, tree, maxEdge - 1);
      }
    }

    return count;
  }
public:
  vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
    int n = edges1.size() + 1;
    int m = edges2.size() + 1;
    vector<vector<int>> tree1(n), tree2(m);
    for (const auto& edge : edges1) {
      tree1[edge[0]].push_back(edge[1]);
      tree1[edge[1]].push_back(edge[0]);
    }
    for (const auto& edge : edges2) {
      tree2[edge[0]].push_back(edge[1]);
      tree2[edge[1]].push_back(edge[0]);
    }

    int maxNodeFromSecondTree = 0;
    if (k > 0) {
      for (int i = 0; i < m; ++i) {
        maxNodeFromSecondTree = max(maxNodeFromSecondTree, countNodeWithMaxEdges(i, -1, tree2, k - 1));
      }
    }

    vector<int> result(n);
    for (int i = 0; i < n; ++i) {
      result[i] = countNodeWithMaxEdges(i, -1, tree1, k) + maxNodeFromSecondTree;
    }

    return result;
  }
};