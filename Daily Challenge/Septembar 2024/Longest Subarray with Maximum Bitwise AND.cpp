// Challenge Date: 14 Sep, 2024
class Solution {
public:
  int longestSubarray(vector<int>& nums) {
    int n = nums.size();
    vector<int> cnt(n, 1);
    for (int i = n - 2; i >= 0; --i) {
      if (nums[i] == nums[i + 1]) cnt[i] += cnt[i + 1];
    }

    int mx = 0, ans = 0;
    for (int x : nums) {
      mx = max(mx, x);
    }

    for (int i = 0; i < n; ++i) {
      if (nums[i] == mx) {
        ans = max(ans, cnt[i]);
      }
    }

    return ans;
  }
};