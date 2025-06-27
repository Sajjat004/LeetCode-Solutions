class Solution {
  bool isValid(vector<int>& nums, int k) {
    int n = nums.size();
    return nums[n - 1] - nums[0] <= k;
  }

public:
  vector<vector<int>> divideArray(vector<int>& nums, int k) {
    int n = nums.size();
    vector<vector<int>> result(n / 3, vector<int>());
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; ++i) {
      result[(i) / 3].push_back(nums[i]);
    }

    for (int i = 0; i < n / 3; ++i) {
      if (!isValid(result[i], k)) {
        return {};
      }
    }

    return result;
  }
};