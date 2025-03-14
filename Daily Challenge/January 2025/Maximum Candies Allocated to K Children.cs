public class Solution {
  public int MaximumCandies(int[] candies, long k) {
    int n = candies.Length;
    int totalCandies = 0;
    int left = 1, right = candies[0];
    for (int i = 0; i < n; i++) {
      totalCandies += candies[i];
      right = Math.Max(right, candies[i]);
    }
    if (totalCandies < k) return 0;
    
    while (left <= right) {
      int mid = (left + right) / 2;
      if (CanAllocateCandies(candies, mid, k)) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }

    return right;
  }

  private bool CanAllocateCandies(int[] candies, int mid, long k) {
    long count = 0;
    for (int i = 0; i < candies.Length; i++) {
      count += (long) candies[i] / mid;
    }

    return count >= k;
  }
}