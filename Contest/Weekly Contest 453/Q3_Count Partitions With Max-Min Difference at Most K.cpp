class Solution {
  const int MOD = 1e9 + 7;
public:
  int countPartitions(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> ways(n + 1, 0);
    vector<int> prefixSum(n + 1, 0);
    ways[0] = prefixSum[0] = 1;

    multiset<int> ms;
    int left = 0;
    for (int i = 1; i <= n; ++i) {
      ms.insert(nums[i - 1]);
      while ((*ms.rbegin() - *ms.begin()) > k) {
        ms.erase(ms.find(nums[left]));
        left++;
      }

      ways[i] = (prefixSum[i - 1] - (left > 0 ? prefixSum[left - 1] : 0) + MOD) % MOD;
      prefixSum[i] = (prefixSum[i - 1] + ways[i]) % MOD;
    }

    return ways[n];
  }
};