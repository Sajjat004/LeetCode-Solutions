class Solution {
public:
  vector<int> closestPrimes(int left, int right) {
    vector<int> primes = getPrimes(right);
    int minDiff = INT_MAX;
    vector<int> result = {-1, -1};

    for (int i = 1; i < primes.size(); ++i) {
      if (primes[i] <= right and primes[i -1] >= left) {
        int diff = primes[i] - primes[i - 1];
        if (diff < minDiff) {
          minDiff = diff;
          result = {primes[i - 1], primes[i]};
        }
      }
    }

    return result;
  }

private:
  vector<int> getPrimes(int n) {
    vector<int> primes;
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i <= n; i++) {
      if (isPrime[i]) {
        primes.push_back(i);
        for (int j = i * 2; j <= n; j += i) {
          isPrime[j] = false;
        }
      }
    }

    return primes;
  }
};