class Solution {
bool isDistinct(vector<int>& nums, int l) {
  unordered_set<int> s;
  for (int i = l; i < nums.size(); ++i) {
    if (s.count(nums[i])) return false;
    s.insert(nums[i]);
  }

  return true;
}

public:
  int minimumOperations(vector<int>& nums) {
    int n = nums.size();
    int operations = 0;
    int left = 0;

    while (!isDistinct(nums, left)) {
      operations++;
      left += 3;
    }

    return operations;
  }
};