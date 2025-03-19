class Solution {
public:
  int minOperations(vector<int>& nums) {
    int n = nums.size();
    int operations = 0;

    for (int i = 0; i < n - 2; ++i) {
      if (nums[i] == 0) {
        operations += 1;
        nums[i] ^= 1;
        nums[i + 1] ^= 1;
        nums[i + 2] ^= 1;
      }
    }

    for (int x : nums) {
      if (x == 0) return -1;
    }

    return operations;
  }
};