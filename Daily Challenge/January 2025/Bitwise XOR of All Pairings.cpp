class Solution {
public:
  int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
    int XOR = 0;

    if (n & 1) {
      for (int i = 0; i < m; i++) {
        XOR ^= nums2[i];
      }
    }

    if (m & 1) {
      for (int i = 0; i < n; i++) {
        XOR ^= nums1[i];
      }
    }

    return XOR;
  }
};