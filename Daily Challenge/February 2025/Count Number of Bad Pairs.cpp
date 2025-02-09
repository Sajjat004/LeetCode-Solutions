class Solution {
  public:
    long long countBadPairs(vector<int>& nums) {
      map<long long, long long> values;
      long long ans = 0;

      for (int i = 0; i < nums.size(); ++i) {
        long long count = values[i - nums[i]];

        ans += i - count;
        values[i - nums[i]]++;
      }

      return ans;
    }
  };