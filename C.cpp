#include <bits/stdc++.h>
using namespace std;

void solution() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  a.erase(unique(a.begin(), a.end()), a.end());

  int cnt = 1;
  int ans = 0;
  for (int i = 1; i < a.size(); ++i) {
    if (a[i] > (a[i - 1] + 1)) {
      ans += (cnt + 1) / 2;
      cnt = 1;
    } else {
      cnt++;
    }
  }
  ans += (cnt + 1) / 2;

  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int tests = 1; cin >> tests;
  while (tests--) {
    solution();
  }
    
  return 0;
}