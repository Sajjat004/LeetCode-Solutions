#include <bits/stdc++.h>
using namespace std;

int minOperationToReach(int x, int k) {
  vector<int> divisors;
  for (int i = 1; i * i <= x; ++i) {
    if (x % i == 0) {
      divisors.push_back(i);
      if (i != x / i) {
        divisors.push_back(x / i);
      }
    }
  }
  
  sort(divisors.begin(), divisors.end());
  unordered_map<int, bool> isDivisor;
  unordered_map<int, int> dp;

  for (int d : divisors) {
    isDivisor[d] = true;
    dp[d] = 101;
  }

  dp[1] = 0;
  for (int val : divisors) {
    if (dp[val] >= 101) continue;
    for (int d : divisors) {
      if (d > k or (val * d) > x) break;
      if (isDivisor[val * d]) {
        dp[val * d] = min(dp[val * d], dp[val] + 1);
      }
    }
  }

  return dp[x];
}

void solution() {
  int x, y, k; cin >> x >> y >> k;
  
  int g = __gcd(x, y);
  x /= g; y /= g;

  int minOperations = minOperationToReach(x, k) + minOperationToReach(y, k);
  
  cout << (minOperations >= 101 ? -1 : minOperations) << endl;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int tests; cin >> tests;
  while (tests--) {
    solution();
  }

  return 0;
}