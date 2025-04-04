#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());

  cout << a[n - 1] - a[0] << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    solve();
  }
    
  return 0;
}