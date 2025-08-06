class Solution {
public:
  int maximumUniqueSubarray(vector<int>& nums) {
    int n = nums.size();
    vector<bool> seen(10001, false);
    int left = 0, right = 0, currentSum = 0, maxSum = 0;

    while (right < n) {
        if (!seen[nums[right]]) {
            seen[nums[right]] = true;
            currentSum += nums[right];
            maxSum = max(maxSum, currentSum);
            right++;
        } else {
            seen[nums[left]] = false;
            currentSum -= nums[left];
            left++;
        }
    }

    return maxSum;
  }
};