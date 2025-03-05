class Solution {
  public:
    long long coloredCells(int n) {
      long long ans = 1LL * n * n * 2;
      ans -= (2LL * n) - 1;

      return ans;
    }
  };