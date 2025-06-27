class Solution {
public:
  int partitionArray(vector<int>& nums, int k) {
    int n = nums.size();
    sort(nums.begin(), nums.end());

    int ans = 0, minVal = nums[0];
    for (int i = 0; i < n; ++i) {
      if (nums[i] - minVal > k) {
        ans++;
        minVal = nums[i];
      }
    }

    return ans + 1;
  }
};