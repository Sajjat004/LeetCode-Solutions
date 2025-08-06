class Solution {
public:
  int countMaxOrSubsets(vector<int>& nums) {
    int n = nums.size(), mxOr = 0, cnt = 0;
    for (int num : nums) {
      mxOr |= num;
    }
    for (int mask = 0; mask < (1 << n); ++mask) {
      int currOr = 0;
      for (int i = 0; i < n; ++i) {
        if (mask & (1 << i)) {
          currOr |= nums[i];
        }
      }
      if (currOr == mxOr) cnt++;
    }

    return cnt;
  }
};