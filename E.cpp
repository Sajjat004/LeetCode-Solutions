#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void dfs(int node, int parent, vector<int>& a, vector<vector<int>>& tree, vector<ll>& dp) {
  for (int child : tree[node]) {
    if (child == parent) continue;
    dp[child] = a[child];
    if (parent != -1) dp[child] = max(dp[child], dp[parent] + a[child] - a[node]);
    
    dfs(child, node, a, tree, dp);
  }
}

void solution() {
  int n; cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  vector<vector<int>> tree(n + 1);
  for (int i = 1; i < n; ++i) {
    int u, v; cin >> u >> v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }

  vector<ll> dp(n + 1, 0);
  dp[1] = a[1];
  dfs(1, -1, a, tree, dp);

  for (int i = 1; i <= n; ++i) {
    cout << dp[i] << ' ';
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int tests = 1; cin >> tests;
  while (tests--) {
    solution();
  }
    
  return 0;
}