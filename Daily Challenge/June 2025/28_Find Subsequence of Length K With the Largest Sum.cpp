class Solution {
public:
  vector<int> maxSubsequence(vector<int>& nums, int k) {
    vector<int> a = nums;
    sort(a.begin(), a.end(), greater<int>());
    map<int, int> taken;
    for (int i = 0; i < k; ++i) {
      taken[a[i]]++;
    }
    vector<int> res;
    for (int i = 0; i < nums.size(); ++i) {
      if (taken[nums[i]] > 0) {
        res.push_back(nums[i]);
        taken[nums[i]]--;
      }
    }
    return res;
  }
};