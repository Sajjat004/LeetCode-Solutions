class Solution {
  const int MOD = (int) 1e9 + 7;
  map<pair<int, int>, int> dp;
  map<pair<int, int>, bool> done;
public:
  int recur(int x, int y) {
    if (x == 0 and y == 0) return 1;
    if (x == 1 and y == 1) return 1;
    if (x == 2 and y == 2) return 2;
    if (x < 0 or y < 0) return 0;
    if (done[{x, y}] == 1) return dp[{x, y}];
    int ans = 0;
    if (x == y) {
      ans += recur(x - 1, y - 1);
      ans %= MOD;
      ans += recur(x - 2, y - 2);
      ans %= MOD;
      ans += recur(x - 2, y - 1);
      ans %= MOD;
      ans += recur(x - 1, y - 2);
      ans %= MOD;
    } else {
      ans += recur(x - 2, y - 2);
      ans %= MOD;
      if (x < y) {
        ans += recur(x - 1, y - 2);
        ans %= MOD;
        ans += recur(x - 2, x - 2);
        ans %= MOD;
      } else {
        ans += recur(x - 2, y - 1);
        ans %= MOD;
        ans += recur(y - 2, y - 2);
        ans %= MOD;
      }
    }
    done[{x, y}] = 1;
    dp[ {x, y}] = ans;
    return ans;
  }
  int numTilings(int n) {
    int ans = recur(n, n);
    return ans;
  }
};