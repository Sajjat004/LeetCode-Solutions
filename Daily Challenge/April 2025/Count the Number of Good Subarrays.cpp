class Solution {
public:
  long long countGood(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int, int> freq;
    long long goodSubarrays = 0;
    int goodPairs = 0;
    int right = 0;

    for (int left = 0; left < n; ++left) {
      while (goodPairs < k && right < n) {
        goodPairs += freq[nums[right]]++;
        ++right;
      }
      if (goodPairs >= k) {
        goodSubarrays += n - right + 1;
      }
      goodPairs -= --freq[nums[left]];
    }

    return goodSubarrays;
  }
};