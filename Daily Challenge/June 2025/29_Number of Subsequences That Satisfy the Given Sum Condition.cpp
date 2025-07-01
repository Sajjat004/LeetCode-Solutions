class Solution {
public:
  int numSubseq(vector<int>& nums, int target) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<int> pow2(n + 1, 1);
    for (int i = 1; i <= n; ++i) {
      pow2[i] = (pow2[i - 1] * 2) % 1000000007;
    }

    int res = 0;
    for (int i = 0; i < n; ++i) {
      int j = upper_bound(nums.begin(), nums.end(), target - nums[i]) - nums.begin() - 1;
      if (j < i) continue;
      res = (res + pow2[j - i]) % 1000000007;
    }
    return res;
  }
};