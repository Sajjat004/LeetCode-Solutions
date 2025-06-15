class Solution {
public:
  vector<int> constructTransformedArray(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n);
    for (int i = 0; i < n; ++i) {
      int nextIndex = (i + nums[i]) % n;
      if (nextIndex < 0) {
        nextIndex += n;
      }
      result[i] = nums[nextIndex];
    }

    return result;
  }
};