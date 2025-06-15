class Solution {
public:
  int maxAdjacentDistance(vector<int>& nums) {
    int n = nums.size();
    if (n < 2) return 0;

    int maxDiff = 0;
    for (int i = 0; i < n; ++i) {
      int nextIndex = (i + 1) % n;
      maxDiff = max(maxDiff, abs(nums[i] - nums[nextIndex]));
    }

    return maxDiff;
  }
};