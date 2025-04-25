class Solution {
  public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
      unordered_map<int, int> cnt;
      int prefixSum = 0;
      cnt[0] = 1;

      long long result = 0;
      for (int i = 0; i < nums.size(); i++) {
        prefixSum += nums[i] % modulo == k ? 1 : 0;
        prefixSum %= modulo;

        int target = (prefixSum - k + modulo) % modulo;
        result += cnt[target];
        cnt[prefixSum]++;
      }

      return result;
    }
  };