vector<vector<pair<int, int>>> graph;

class LowestCommonAncestor {
 private:
  vector<int> depth;
  vector<vector<int>> sparseTable;
  vector<vector<long long>> pathSum;

  void dfs(int u, int par = -1, int d = 0) {
    depth[u] = d;
    sparseTable[u][0] = par;
    for (int k = 1; k <= 20; ++k) {
      if (sparseTable[u][k - 1] == -1) break;
      sparseTable[u][k] = sparseTable[sparseTable[u][k - 1]][k - 1];
      pathSum[u][k] = pathSum[u][k - 1] + pathSum[sparseTable[u][k - 1]][k - 1];
    }
    for (auto& [v, w] : graph[u]) {
      if (v == par) continue;
      pathSum[v][0] = w;
      dfs(v, u, d + 1);
    }
  }
  public:
  LowestCommonAncestor(int n, int src) {
    depth.assign(n + 2, 0);
    sparseTable.assign(n + 2, vector<int>(22, -1));
    pathSum.assign(n + 2, vector<long long>(22, 0));
    dfs(src);
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

  int getDepth(int u) {
    return depth[u];
  }

  long long getPathSum(int u, int v) {
    long long sum = 0;
    for (int k = 20; k >= 0; --k) {
      if ((depth[u] - (1 << k)) >= depth[v]) {
        sum += pathSum[u][k];
        u = sparseTable[u][k];
      }
    }

    return sum;
  }

  int getQueryNode1(int u, int v) {
    long long totalSum = getPathSum(u, v);
    long long halfSum = 0;
    for (int k = 20; k >= 0; --k) {
      if ((depth[u] - (1 << k)) >= depth[v]) {
        if (halfSum + pathSum[u][k] < (totalSum / 2)) {
          halfSum += pathSum[u][k];
          u = sparseTable[u][k];
        }
      }
    }
    
    return sparseTable[u][0];
  }

  int getQueryNode2(int u, int v) {
    long long totalSum = getPathSum(u, v);
    long long halfSum = 0;
    for (int k = 20; k >= 0; --k) {
      if ((depth[u] - (1 << k)) >= depth[v]) {
        if (halfSum + pathSum[u][k] <= totalSum / 2) {
          halfSum += pathSum[u][k];
          u = sparseTable[u][k];
        }
      }
    }

    return u;
  }

  int getQueryNode3(int u, int v) {
    int lcaNode = query(u, v);
    long uSum = getPathSum(u, lcaNode);
    long vSum = getPathSum(v, lcaNode);
    long long totalSum = uSum + vSum;
    long long halfSum = 0;
    
    if (uSum >= vSum) {
      v = lcaNode;
      for (int k = 20; k >= 0; --k) {
        if ((depth[u] - (1 << k)) >= depth[v]) {
          if (halfSum + pathSum[u][k] < (totalSum / 2)) {
            halfSum += pathSum[u][k];
            u = sparseTable[u][k];
          }
        }
      }
      
      return sparseTable[u][0];
    }

    u = v;
    v = lcaNode;
    for (int k = 20; k >= 0; --k) {
      if ((depth[u] - (1 << k)) >= depth[v]) {
        if (halfSum + pathSum[u][k] <= totalSum / 2) {
          halfSum += pathSum[u][k];
          u = sparseTable[u][k];
        }
      }
    }

    return u;
  }
};

class Solution {
public:
  vector<int> findMedian(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
    graph = vector<vector<pair<int, int>>>(n + 2);
    for (const auto& edge : edges) {
      int u = edge[0], v = edge[1], w = edge[2];
      graph[u].emplace_back(v, w);
      graph[v].emplace_back(u, w);
    }

    LowestCommonAncestor lca(n, 0);
    vector<int> result;

    for (const auto& query : queries) {
      int u = query[0], v = query[1];
      if (u == v) {
        result.push_back(u);
        continue;
      }

      int lcaNode = lca.query(u, v);

      if (u == lcaNode || v == lcaNode) {
        if (lca.getDepth(u) > lca.getDepth(v)) {
          result.push_back(lca.getQueryNode1(u, v));
        } else {
          result.push_back(lca.getQueryNode2(v, u));
        }
      } else {
        result.push_back(lca.getQueryNode3(u, v));
      }
    }

    return result;
  }
};