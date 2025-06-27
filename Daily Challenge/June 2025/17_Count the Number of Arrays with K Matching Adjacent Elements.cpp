class NumberTheory {
  vector<int> factorial;
  vector<int> inverseFactorial;

public:
  int add(int a, int b, const int mod) { return (a + b) % mod; }
  int subtract(int a, int b, const int mod) { return (a - b + mod) % mod; }
  int multiply(int a, int b, const int mod) { return 1LL * a * b % mod; }

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

  int modInverse(int a, const int mod) {
    return power(a, mod - 2, mod);
  }

  void buildFactorial(int n, const int mod) {
    factorial.resize(n + 1);
    inverseFactorial.resize(n + 1);

    factorial[0] = 1;
    for (int i = 1; i <= n; ++i) {
      factorial[i] = 1LL * factorial[i - 1] * i % mod;
    }

    inverseFactorial[n] = power(factorial[n], mod - 2, mod);
    for (int i = n - 1; i >= 0; --i) {
      inverseFactorial[i] = 1LL * inverseFactorial[i + 1] * (i + 1) % mod;
    }
  }

  int getFactorial(int n) { return factorial[n]; }
  int getInverseFactorial(int n) { return inverseFactorial[n]; }

  // Before using this function, you need to call buildFactorial(n, mod)
  int getCombination(int n, int k, const int mod) {
    if (k < 0 || k > n) return 0;
    return 1LL * factorial[n] * inverseFactorial[k] % mod * inverseFactorial[n - k] % mod;
  }
};

class Solution {
public:
  int countGoodArrays(int n, int m, int k) {
    NumberTheory ntheory;
    const int mod = 1e9 + 7;
    ntheory.buildFactorial(n, mod);

    int c1 = ntheory.getCombination(n - 1, k, mod);
    int c2 = 1LL * m * ntheory.power(m - 1, n - k - 1, mod) % mod;

    return ntheory.multiply(c1, c2, mod);
  }
};