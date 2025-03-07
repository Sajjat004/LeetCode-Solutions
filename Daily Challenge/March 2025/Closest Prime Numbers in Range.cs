public class Solution {
  public int[] ClosestPrimes(int left, int right) {
    var primes = GetPrimes(right);
    int minDiff = int.MaxValue;
    int[] closestPrimes = new int[] {-1, -1};

    for (int i = 1; i < primes.Length; ++i) {
      if (primes[i] <= right && primes[i - 1] >= left) {
        int diff = primes[i] - primes[i - 1];
        if (diff < minDiff) {
          minDiff = diff;
          closestPrimes[0] = primes[i - 1];
          closestPrimes[1] = primes[i];
        }
      }
    }

    return closestPrimes;
  }

  private int[] GetPrimes(int n) {
    var primes = new List<int>();
    bool[] isPrime = new bool[n + 1];
    for (int i = 0; i <= n; ++i) isPrime[i] = true;

    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i <= n; ++i) {
      if (isPrime[i]) {
        primes.Add(i);
        for (int j = i * 2; j <= n; j += i) {
          isPrime[j] = false;
        }
      }
    }

    return primes.ToArray();
  }
}