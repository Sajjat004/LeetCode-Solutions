class Solution {
  void countSubTreeNodes(int node, int parent, vector<vector<int>>& tree, vector<vector<int>>& count) {
    count[node][0] = 1;
    for (int child : tree[node]) {
      if (child == parent) continue;
      countSubTreeNodes(child, node, tree, count);
      count[node][0] += count[child][1];
      count[node][1] += count[child][0];
    }
  }

  void countFullTreeNodes(int node, int parent, vector<vector<int>>& tree, vector<vector<int>>& count) {
    for (int child : tree[node]) {
      if (child == parent) continue;
      int parentOddExceptChild = count[node][1] - count[child][0];
      int parentEvenExceptChild = count[node][0] - count[child][1];
      count[child][0] += parentOddExceptChild;
      count[child][1] += parentEvenExceptChild;
      countFullTreeNodes(child, node, tree, count);
    }
  }
  
public:
  vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
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

    vector<vector<int>> countTree1(n, vector<int>(2, 0));
    vector<vector<int>> countTree2(m, vector<int>(2, 0));
    countSubTreeNodes(0, -1, tree1, countTree1);
    countSubTreeNodes(0, -1, tree2, countTree2);
    countFullTreeNodes(0, -1, tree1, countTree1);
    countFullTreeNodes(0, -1, tree2, countTree2);

    int maxOddCountInTree2 = 0;
    for (int i = 0; i < m; ++i) {
      maxOddCountInTree2 = max(maxOddCountInTree2, countTree2[i][1]);
    }

    vector<int> result(n);
    for (int i = 0; i < n; ++i) {
      result[i] = countTree1[i][0] + maxOddCountInTree2;
    }

    return result;
  }
};