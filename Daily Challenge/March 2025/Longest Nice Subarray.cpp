class Solution {
public:
  int longestNiceSubarray(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> prefixSum(n + 1, vector<int>(31, 0));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < 31; ++j) {
        prefixSum[i + 1][j] = prefixSum[i][j] + ((nums[i] >> j) & 1);
      }
    }

    int result = 1;
    for (int i = 1; i <= n; ++i) {
      int left = i, right = n;

      while (left <= right) {
        int mid = (left + right) / 2;
        if (isNice(prefixSum, i, mid)) {
          result = max(result, mid - i + 1);
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      }
    }

    return result;
  }

private:
  bool isNice(vector<vector<int>>& prefixSum, int left, int right) {
    for (int i = 0; i < 31; ++i) {
      if (prefixSum[right][i] - prefixSum[left - 1][i] > 1) return false;
    }

    return true;
  }
};