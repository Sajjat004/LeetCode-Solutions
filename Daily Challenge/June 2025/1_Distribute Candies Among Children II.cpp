// solution using brute force
// Time Complexity: O(min(limit, n))
// Space Complexity: O(1)

class Solution {
public:
  long long distributeCandies(int n, int limit) {
    long long ans = 0;
    for (int i = 0; i <= min(limit, n); ++i) {
      if (n - i > 2 * limit) continue;
      ans += min(n - i, limit) - max(0, n - i - limit) + 1;
    }
    
    return ans;
  }
};

// solution using combinatorial counting + stars and bars principle + inclusion-exclusion principle
// Time Complexity: O(1)
// Space Complexity: O(1)
class Solution {
  long long combinations(int n) {
    if (n < 0) return 0;
    return (long long)n * (n - 1) / 2;
  }

public:
  long long distributeCandies(int n, int limit) {
    long long allCombinations = combinations(n + 2);
    long long oneAboveLimit = 3LL * combinations(n - limit + 1);
    long long twoAboveLimit = 3LL * combinations(n - (limit + 1) * 2 + 2);
    long long threeAboveLimit = combinations(n - 3 * (limit + 1) + 2);
    long long invalidCombinations = oneAboveLimit - twoAboveLimit + threeAboveLimit;
    long long validCombinations = allCombinations - invalidCombinations;

    return validCombinations;
  }
};
