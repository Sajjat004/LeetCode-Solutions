#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int test; cin >> test;
  while (test--) {
    int n, m; cin >> n >> m;

    vector<int> mn(n + 1, n);
    for (int i = 0; i < m; ++i) {
      int x, y; cin >> x >> y;
      if (x > y) swap(x, y);
      mn[x] = min(mn[x], y - 1);
    }

    for (int i = n - 1; i >= 1; --i) {
      mn[i] = min(mn[i], mn[i + 1]);
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      ans += (mn[i] - i);
    }

    cout << ans << '\n';
  }
    
  return 0;
}