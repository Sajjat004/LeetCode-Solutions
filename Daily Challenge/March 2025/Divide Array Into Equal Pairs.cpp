class Solution {
public:
  bool divideArray(vector<int>& nums) {
    map<int, int> count;
    for (int num : nums) {
      count[num]++;
    }

    for (auto& [num, freq] : count) {
      if (freq % 2 != 0) {
        return false;
      }
    }

    return true;
  }
};