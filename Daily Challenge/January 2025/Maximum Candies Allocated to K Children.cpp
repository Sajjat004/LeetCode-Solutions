class Solution {
public:
  int maximumCandies(vector<int>& candies, long long k) {
    int n = candies.size();

    long long totalCandies = 0;
    int left = 1, right = candies[0];
    for (int i = 0; i < n; ++i) {
      totalCandies += candies[i];
      right = max(right, candies[i]);
    }
    if (totalCandies < k) return 0;

    while (left <= right) {
      int mid = (left + right) / 2;
      long long sum = 0;
      for (int i = 0; i < n; ++i) {
        sum += (long long) candies[i] / mid;
      }
      if (sum >= k) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    return right;
  }
};