#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int test; cin >> test;
  while (test--) {
    int n; cin >> n;
    string s; cin >> s;
    s = "0" + s;

    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (s[i] != s[i - 1]) {
            ans++;
        }
    }

    cout << ans << '\n';
  }
    
  return 0;
}