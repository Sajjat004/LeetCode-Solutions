class Solution {
public:
  int minimumIndex(vector<int>& nums) {
    int n = nums.size();

    vector<bool> leftDominant(n, false);
    vector<bool> rightDominant(n, false);
    unordered_map<int, int> leftCount, rightCount;

    for (int i = 0; i < n; ++i) {
      leftCount[nums[i]]++;
      if (leftCount[nums[i]] > (i + 1) / 2) {
        leftDominant[i] = true;
      }
    }
    for (int i = n - 1; i >= 0; --i) {
      rightCount[nums[i]]++;
      if (rightCount[nums[i]] > (n - i) / 2) {
        rightDominant[i] = true;
      }
    }

    for (int i = 0; i < n - 1; ++i) {
      if (leftDominant[i] && rightDominant[i + 1]) {
        return i + 1;
      }
    }
    return -1;
  }
};