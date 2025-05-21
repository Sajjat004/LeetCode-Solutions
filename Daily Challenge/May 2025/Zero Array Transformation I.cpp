class Solution {
public:
  bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    int n = nums.size();
    vector<int> prefixSum(n + 2, 0);
  

    for (const auto& query : queries) {
      int left = query[0] + 1;
      int right = query[1] + 1;

      prefixSum[left] += 1;
      prefixSum[right + 1] -= 1;
    }

    for (int i = 1; i <= n; ++i) {
      prefixSum[i] += prefixSum[i - 1];
      if (prefixSum[i] < nums[i - 1]) {
        return false;
      }
    }

    return true;
  }
};