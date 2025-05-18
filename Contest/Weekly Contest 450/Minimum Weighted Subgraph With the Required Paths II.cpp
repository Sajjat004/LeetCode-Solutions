vector<vector<int>> graph;
map<pair<int, int>, int> edgesWeight;

class LowestCommonAncestor {
 private:
  vector<int> depth;
  vector<vector<int>> sparseTable;
  vector<vector<int>> edgesWeightedSparseTable;

  void dfs(int u, int par = -1, int d = 0) {
    depth[u] = d;
    sparseTable[u][0] = par;
    edgesWeightedSparseTable[u][0] = edgesWeight[{u, par}];
    for (int k = 1; k <= 20; ++k) {
      if (sparseTable[u][k - 1] == -1) break;
      sparseTable[u][k] = sparseTable[sparseTable[u][k - 1]][k - 1];
      edgesWeightedSparseTable[u][k] = edgesWeightedSparseTable[u][k - 1] + edgesWeightedSparseTable[sparseTable[u][k - 1]][k - 1];
    }
    for (int v : graph[u]) {
      if (v == par) continue;
      dfs(v, u, d + 1);
    }
  }
 public:
  LowestCommonAncestor(int n, int src) {
    depth.assign(n + 2, 0);
    sparseTable.assign(n + 2, vector<int>(22, -1));
    edgesWeightedSparseTable.assign(n + 2, vector<int>(22, 0));
    dfs(src);
  }

  int getDepth(int u) {
    return depth[u];
  }

  int query(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int k = 20; k >= 0; --k) {
      if ((depth[u] - (1 << k)) >= depth[v]) u = sparseTable[u][k];
    }
    if (u == v) return u;
    for (int k = 20; k >= 0; --k) {
      if (sparseTable[u][k] != -1 and sparseTable[u][k] != sparseTable[v][k]) {
        u = sparseTable[u][k];
        v = sparseTable[v][k];
      }
    }
    return sparseTable[u][0];
  }

  int getPathSum(int node, int par) {
    int sum = 0;
    for (int k = 20; k >= 0; --k) {
      if (depth[node] - (1 << k) >= depth[par]) {
        sum += edgesWeightedSparseTable[node][k];
        node = sparseTable[node][k];
      }
    }

    return sum;
  }
};

class Solution {
public:
  vector<int> minimumWeight(vector<vector<int>>& edges, vector<vector<int>>& queries) {
    int n = edges.size() + 1;
    graph = vector<vector<int>>(n + 2);
    edgesWeight.clear();

    for (auto& edge : edges) {
      int u = edge[0], v = edge[1], w = edge[2];
      graph[u].push_back(v);
      graph[v].push_back(u);
      edgesWeight[{u, v}] = w;
      edgesWeight[{v, u}] = w;
    }

    LowestCommonAncestor lca(n, 0);
    vector<int> ans;

    for (auto& query : queries) {
      int src1 = query[0], src2 = query[1], dest = query[2];
      
      int lca1 = lca.query(src1, dest);
      int lca2 = lca.query(src2, dest);
      int lca3 = lca.query(src1, src2);

      int sum1 = 0;

      if (lca.getDepth(lca1) > lca.getDepth(lca2) and lca.getDepth(lca1) > lca.getDepth(lca3)) {
        sum1 = lca.getPathSum(src1, lca1);
        sum1 += lca.getPathSum(dest, lca1);
        int tempLca = lca.query(lca1, src2);
        sum1 += lca.getPathSum(src2, tempLca);
        sum1 += lca.getPathSum(lca1, tempLca);
      } else if (lca.getDepth(lca2) > lca.getDepth(lca1) and lca.getDepth(lca2) > lca.getDepth(lca3)) {
        sum1 = lca.getPathSum(src2, lca2);
        sum1 += lca.getPathSum(dest, lca2);
        int tempLca = lca.query(lca2, src1);
        sum1 += lca.getPathSum(src1, tempLca);
        sum1 += lca.getPathSum(lca2, tempLca);
      } else {
        sum1 = lca.getPathSum(src1, lca3);
        sum1 += lca.getPathSum(src2, lca3);
        int tempLca = lca.query(lca3, dest);
        sum1 += lca.getPathSum(dest, tempLca);
        sum1 += lca.getPathSum(lca3, tempLca);
      }

      ans.push_back(sum1);
    }

    return ans;
  }
};