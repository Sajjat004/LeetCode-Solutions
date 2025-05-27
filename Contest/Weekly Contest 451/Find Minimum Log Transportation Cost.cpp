class Solution {
public:
  long long minCuttingCost(int n, int m, int k) {
    long long totalCost = 0;

    while (n > k) {
      totalCost += 1LL * (n - k) * k;
      n -= k;
    }
    while (m > k) {
      totalCost += 1LL * (m - k) * k;
      m -= k;
    }

    return totalCost;
  }
};