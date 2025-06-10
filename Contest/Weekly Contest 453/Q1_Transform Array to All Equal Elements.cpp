class Solution {
  bool isPossible(vector<int> nums, int k, int x) {
    int n = nums.size();
    int operations = 0;
    for (int i = 0; i + 1 < n; ++i) {
      if (nums[i] != x) {
        nums[i] *= -1;
        nums[i + 1] *= -1;
        operations++;
      }
    }

    return operations <= k and nums[n - 1] == x;
  }

public:
  bool canMakeEqual(vector<int>& nums, int k) {
    bool possible = false;
    possible |= isPossible(nums, k, 1);
    possible |= isPossible(nums, k, -1);
    return possible;
  }
};