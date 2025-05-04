class Solution {
public:
  long long countSubarrays(vector<int>& nums, int k) {
    int maxElement = *max_element(nums.begin(), nums.end());

    int n = nums.size();
    long long ans = 0;
    int countMaxElement = 0;
    int right = 0;

    for (int left = 0; left < n; ++left) {
      while (right < n && countMaxElement < k) {
        if (nums[right] == maxElement) {
          countMaxElement++;
        }
        right++;
      }

      if (countMaxElement >= k) {
        ans += n - right + 1;
      }

      if (nums[left] == maxElement) {
        countMaxElement--;
      }
    }

    return ans;
  }
};