#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll getMaxCoins() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  vector<ll> segment;
  vector<bool> segmentType;
  segment.push_back(0LL);
  segmentType.push_back(false);

  int index = 0;
  while (index < n) {
    int start = index;

    ll sum = 0;
    while (start < n) {
      if (a[start] < 0 and a[index] < 0) {
        sum += abs(a[start]);
      } else if (a[start] >= 0 and a[index] >= 0) {
        sum += a[start];
      } else {
        break;
      }
      start++;
    }

    segment.push_back(sum);
    segmentType.push_back(a[index] > 0);
    index = start;
  }

  int m = segment.size();
  vector<vector<ll>> prefixSum(m + 2, vector<ll>(2, 0));
  vector<vector<ll>> sufixSum(m + 2, vector<ll>(2, 0));

  for (int i = 1; i < m; i++) {
    prefixSum[i][0] = prefixSum[i - 1][0];
    prefixSum[i][1] = prefixSum[i - 1][1];
    if (segmentType[i]) {
      prefixSum[i][1] += segment[i];
    } else {
      prefixSum[i][0] += segment[i];
    }
  }

  for (int i = m - 1; i >= 1; i--) {
    sufixSum[i][0] = sufixSum[i + 1][0];
    sufixSum[i][1] = sufixSum[i + 1][1];
    if (segmentType[i]) {
      sufixSum[i][1] += segment[i];
    } else {
      sufixSum[i][0] += segment[i];
    }
  }

  ll ans = 0LL;
  for (int i = 1; i < m; ++i) {
    if (segmentType[i]) {
      ans = max(ans, prefixSum[i][1] + sufixSum[i + 1][0]);
    } else {
      ans = max(ans, sufixSum[i][0] + prefixSum[i - 1][1]);
    }
  }

  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int test; cin >> test;
  while (test--) {
    cout << getMaxCoins() << '\n';
  }
    
  return 0;
}