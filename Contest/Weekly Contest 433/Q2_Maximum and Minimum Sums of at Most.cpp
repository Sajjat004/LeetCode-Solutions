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

const int MOD = 1e9 + 7;

class Solution {
public:
	int minMaxSums(vector<int>& nums, int k) {
		int n = nums.size();
		NumberTheory nt;
		nt.buildFactorial(n, MOD);

		sort(nums.begin(), nums.end());
		int minSum = 0, maxSum = 0;
		for (int i = 0; i < n; ++i) {
			int sum = 1;
			int remaining = n - i - 1;
			for (int j = 1; j < k; ++j) {
				sum += nt.getCombination(remaining, j, MOD);
				sum %= MOD;
			}
			minSum += (1LL * nums[i] * sum) % MOD;
			minSum %= MOD;
		}

		for (int i = n - 1; i >= 0; --i) {
			int sum = 1;
			int remaining = i;
			for (int j = 1; j < k; ++j) {
				sum += nt.getCombination(remaining, j, MOD);
				sum %= MOD;
			}
			maxSum += (1LL * nums[i] * sum) % MOD;
			maxSum %= MOD;
		}

		return (maxSum + minSum) % MOD;
	}
};