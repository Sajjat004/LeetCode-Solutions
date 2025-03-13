class Solution {
public:
  int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
    int n = nums.size();
    int left = 0, right = queries.size();

    if (!canFormZeroArray(nums, queries, right)) return -1;

    while (left < right) {
      int mid = left + (right - left) / 2;
      if (canFormZeroArray(nums, queries, mid)) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }

    return left;
  }

  bool canFormZeroArray(vector<int>& nums, vector<vector<int>>& queries, int k) {
    int n = nums.size();
    int sum = 0;
    vector<int> diff(n + 1);

    for (int queryIndex = 0; queryIndex < k; ++queryIndex) {
      int start = queries[queryIndex][0];
      int end = queries[queryIndex][1];
      int val = queries[queryIndex][2];

      diff[start] += val;
      diff[end + 1] -= val;
    }

    for (int numIndex = 0; numIndex < n; ++numIndex) {
      sum += diff[numIndex];
      if (sum < nums[numIndex]) return false;
    }

    return true;
  }
};