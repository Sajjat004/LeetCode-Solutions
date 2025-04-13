class Solution {
public:
  int countGoodNumbers(long long n) {
    return 1LL * power(5, (n + 1) / 2, 1000000007) * power(4, n / 2, 1000000007) % 1000000007;
  }

private:
  int power(int base, long long exp, int mod) {
    int result = 1;
    while (exp > 0) {
      if (exp % 2 == 1) {
        result = (1LL * result * base) % mod;
      }
      base = (1LL * base * base) % mod;
      exp /= 2;
    }
    return result;
  }
};