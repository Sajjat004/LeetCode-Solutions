#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll getAns(vector<pair<int, int>>& a) {
  ll n = a.size();
  ll minY = INT_MAX, maxY = INT_MIN;
  for (int i = 0; i < n; ++i) {
    minY = min(minY, (ll) a[i].second);
    maxY = max(maxY, (ll) a[i].second);
  }
  ll yLen = maxY - minY + 1;
  if (a[0].first == a[n - 1].first) {
    return yLen;
  }

  ll xLen = a[n - 1].first - a[1].first + 1;
  minY = INT_MAX;
  maxY = INT_MIN;
  for (int i = 1; i < n; ++i) {
    minY = min(minY, (ll) a[i].second);
    maxY = max(maxY, (ll) a[i].second);
  }
  yLen = maxY - minY + 1;
  
  ll ans1 = xLen * yLen;
  if (n > ans1) {
    ll extra = (ll) n - ans1;
    ans1 += min(((extra + xLen - 1) / xLen) * xLen, ((extra + yLen - 1) / yLen) * yLen);
  }

  xLen = a[n - 2].first - a[0].first + 1;
  minY = INT_MAX;
  maxY = INT_MIN;
  for (int i = 0; i < (n - 1); ++i) {
    minY = min(minY, (ll) a[i].second);
    maxY = max(maxY, (ll) a[i].second);
  }
  yLen = maxY - minY + 1;
  
  ll ans2 = xLen * yLen;
  if (n > ans2) {
    ll extra = n - ans2;
    ans2 += min(((extra + xLen - 1) / xLen) * xLen, ((extra + yLen - 1) / yLen) * yLen);
  }

  return min(ans1, ans2);
}

void solution() {
  int n; cin >> n;
  vector<pair<int, int>> a;
  vector<pair<int, int>> b;
  for (int i = 0; i < n; ++i) {
    int x, y; cin >> x >> y;
    a.push_back({x, y});
    b.push_back({y, x});
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  ll ans1 = getAns(a);
  ll ans2 = getAns(b);

  cout << min(ans1, ans2) << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int tests = 1; cin >> tests;
  while (tests--) {
    solution();
  }
    
  return 0;
}