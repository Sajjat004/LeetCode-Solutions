class Solution {
public:
  int maxSum(vector<int>& nums) {
    set<int> s;
    for (int i = 0; i < nums.size(); ++i) {
      s.insert(nums[i]);
    }

    if (*s.rbegin() < 0) {
      return *s.rbegin();
    }

    int sum = 0;
    for (int x : s) {
      if (x < 0) continue;
      sum += x;
    }

    return sum;
  }
};