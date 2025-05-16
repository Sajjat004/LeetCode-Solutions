
class Solution {
  const int MOD = 1e9 + 7;
  vector<int> factorial;
  vector<int> inverseFactorial;

  int moduleMultiply(int a, int b, const int mod) {
    return (1LL * (a % mod) * (b % mod)) % mod;
  }

  int power(int base, int exp, const int mod) {
    int res = 1 % mod;
    base %= mod;
    if (base < 0) base += mod;

    while (exp) {
      if (exp & 1) res = 1LL * res * base % mod;
      base = 1LL * base * base % mod;
      exp >>= 1;
    }

    return res;
  }

  void precomputeFactorials(int n, const int mod) {
    for (int i = 2; i <= n; ++i) {
      factorial[i] = 1LL * factorial[i - 1] * i % mod;
    }

    inverseFactorial[n] = power(factorial[n], mod - 2, mod);
    for (int i = n - 1; i >= 0; --i) {
      inverseFactorial[i] = 1LL * inverseFactorial[i + 1] * (i + 1) % mod;
    }
  }

  int totalWaysToPermute;
  vector<vector<vector<int>>> dp;
  vector<int> countFrequency;

  int countPermutation(int digit, int leftover, int target) {
    if (digit == 10 and leftover == 0 and target == 0) return totalWaysToPermute;
    if (target < 0) return 0;
    if (leftover == 0 and target != 0) return 0;
    if (digit == 10) return 0;
    if (dp[digit][leftover][target] != -1) return dp[digit][leftover][target];

    int returnedPermutation = 0;

    for (int i = 0; i <= countFrequency[digit]; ++i) {
      if (i <= leftover) {
        int waysForCurrentDigit = moduleMultiply(inverseFactorial[i], inverseFactorial[countFrequency[digit] - i], MOD);
        int ans = moduleMultiply(waysForCurrentDigit, countPermutation(digit + 1, leftover - i, target - digit * i), MOD);
        returnedPermutation = (returnedPermutation + ans) % MOD;
      }
    }

    return dp[digit][leftover][target] = returnedPermutation;
  }

public:
  Solution() {
    factorial = vector<int>(82, 1);
    inverseFactorial = vector<int>(82, 1);
    precomputeFactorials(81, MOD);
  }

  int countBalancedPermutations(string num) {
    int n = num.size();
    countFrequency = vector<int>(10, 0);
    int totalSum = 0;
    for (char c : num) {
      countFrequency[c - '0']++;
      totalSum += c - '0';
    }

    if (totalSum % 2 != 0) return 0;

    dp = vector<vector<vector<int>>>(10, vector<vector<int>>(42, vector<int>(42 * 9, -1)));
    totalWaysToPermute = moduleMultiply(factorial[n / 2], factorial[(n + 1) / 2], MOD);

    return countPermutation(0, n / 2, totalSum / 2);
  }
};