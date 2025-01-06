class Solution {
public:
  int waysToSplitArray(vector<int>& nums) {
    int n = nums.size();
    vector<long long> prefix(n, 0);
    for (int i = 0; i < n; ++i) {
      prefix[i] = nums[i];
      if (i > 0) {
        prefix[i] += prefix[i - 1];
      }
    }

    int splits = 0;
    for (int i = 0; i < (n - 1); ++i) {
      if (prefix[i] >= (prefix[n - 1] - prefix[i])) splits++;
    }

    return splits;
  }
};