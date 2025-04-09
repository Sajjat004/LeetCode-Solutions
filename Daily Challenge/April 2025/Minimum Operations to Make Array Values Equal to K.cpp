class Solution {
public:
  int minOperations(vector<int>& nums, int k) {
    set<int> s;
    for (int x : nums) {
      s.insert(x);
    }

    int operations = 0;
    for (int x : s) {
      if (x < k) return -1;
      if (x > k) operations++;
    }

    return operations;
  }
};