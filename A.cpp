#include <bits/stdc++.h>
using namespace std;

int getInteger(const string& s) {
  int num = 0;
  for (char c : s) {
    if (isdigit(c)) {
      num = num * 10 + (c - '0');
    }
  }
  return num;
}

void solution() {
  string s; cin >> s;
  int n = getInteger(s);
  int sqr = sqrt(n);
  if ((sqr * sqr) == n) {
    cout << 0 << ' ' << sqr << '\n';
  } else {
    cout << -1 << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int tests = 1; cin >> tests;
  while (tests--) {
    solution();
  }
    
  return 0;
}