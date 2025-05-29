#include <bits/stdc++.h>
using namespace std;

void solution() {
  int n, k; cin >> n >> k;
  string s; cin >> s;
  int ones = 0, zeros = 0;
  for (char c : s) {
    if (c == '1') {
      ones++;
    } else {
      zeros++;
    }
  }

  while (k > 0) {
    if (ones >= zeros and ones >= 2) {
      ones -= 2;
    } else if (zeros >= ones and zeros >= 2) {
      zeros -= 2;
    } else {
      cout << "NO\n";
      return;
    }
    k--;
  }

  cout << (abs(ones - zeros) <= 1 ? "YES\n" : "NO\n");
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int tests = 1; cin >> tests;
  while (tests--) {
    solution();
  }
    
  return 0;
}