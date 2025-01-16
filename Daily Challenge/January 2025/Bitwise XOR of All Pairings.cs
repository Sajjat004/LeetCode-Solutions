public class Solution {
  public int XorAllNums(int[] nums1, int[] nums2) {
    int n = nums1.Length;
    int m = nums2.Length;
    int XOR = 0;

    if (n % 2 == 1) {
      for (int i = 0; i < m; i++) {
        XOR ^= nums2[i];
      }
    }
    if (m % 2 == 1) {
      for (int i = 0; i < n; i++) {
        XOR ^= nums1[i];
      }
    }

    return XOR;
  }
}