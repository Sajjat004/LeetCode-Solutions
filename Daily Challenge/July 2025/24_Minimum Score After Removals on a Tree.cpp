class Solution {
  void dfs(int u, int par, vector<int>& nums, vector<vector<int>>& adj, vector<int>& subTreeXor, vector<pair<int, int>>& edges) {
    subTreeXor[u] = nums[u];
    for (int v : adj[u]) {
      if (v != par) {
        dfs(v, u, nums, adj, subTreeXor, edges);
        edges.push_back({u, v});
        subTreeXor[u] ^= subTreeXor[v];
      }
    }
  }

  void dfs1(int u, int par, int d, vector<vector<int>>& adj, vector<int>& dep, vector<vector<int>>& table) {
    dep[u] = d;
    table[u][0] = par;
    for (int k = 1; k < 22; ++k) {
      if (table[u][k - 1] != -1) {
        table[u][k] = table[table[u][k - 1]][k - 1];
      }
    }

    for (int v : adj[u]) {
      if (v != par) {
        dfs1(v, u, d + 1, adj, dep, table);
      }
    }
  }

  int findLCA(int u, int v, vector<int>& dep, vector<vector<int>>& table) {
    if (dep[u] < dep[v]) swap(u, v);
    for (int k = 20; k >= 0; --k) {
      if (dep[u] - (1 << k) >= dep[v]) {
        u = table[u][k];
      }
    }
    if (u == v) return u;
    for (int k = 20; k >= 0; --k) {
      if (table[u][k] != -1 && table[u][k] != table[v][k]) {
        u = table[u][k];
        v = table[v][k];
      }
    }
    return table[u][0];
  }

public:
  int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
    int n = nums.size();
    vector<vector<int>> adj(n);
    for (const auto& edge : edges) {
      adj[edge[0]].push_back(edge[1]);
      adj[edge[1]].push_back(edge[0]);
    }

    vector<int> subTreeXor(n, 0);
    vector<pair<int, int>> edgeList;
    dfs(0, -1, nums, adj, subTreeXor, edgeList);

    vector<int> dep(n, 0);
    vector<vector<int>> table(n, vector<int>(22, -1));
    dfs1(0, -1, 0, adj, dep, table);

    int res = INT_MAX;

    for (int i = 0; i < edgeList.size(); ++i) {
      for (int j = i + 1; j < edgeList.size(); ++j) {
        int u1 = edgeList[i].first, v1 = edgeList[i].second;
        int u2 = edgeList[j].first, v2 = edgeList[j].second;

        int x = 0, y = 0, z = 0;
        int lca = findLCA(v1, v2, dep, table);
        if (lca == v1) {
          x = subTreeXor[0] ^ subTreeXor[v1];
          y = subTreeXor[v1] ^ subTreeXor[v2];
          z = subTreeXor[v2];
        } else if (lca == v2) {
          x = subTreeXor[0] ^ subTreeXor[v2];
          y = subTreeXor[v1] ^ subTreeXor[v2];
          z = subTreeXor[v1];
        } else {
          x = subTreeXor[v1];
          y = subTreeXor[v2];
          z = subTreeXor[0] ^ x ^ y;
        }

        res = min(res, max({x, y, z}) - min({x, y, z}));
      }
    }

    return res;
  }
};