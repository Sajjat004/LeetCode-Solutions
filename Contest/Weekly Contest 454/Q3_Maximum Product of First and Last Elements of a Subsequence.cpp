class Solution {
public:
  long long maximumProduct(vector<int>& nums, int m) {
    int n = nums.size();
    vector<int> mx(n, INT_MIN);
    vector<int> mn(n, INT_MAX);

    if (m == 1) {
      long long ans = LLONG_MIN;
      for (int i = 0; i < n; ++i) {
        ans = max(ans, 1LL * nums[i] * nums[i]);
      }
      return ans;
    }
    mx[n - 1] = nums[n - 1];
    mn[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; --i) {
      mx[i] = max(mx[i + 1], nums[i]);
      mn[i] = min(mn[i + 1], nums[i]);
    }

    long long ans = LLONG_MIN;
    for (int i = 0; i + m - 1 < n; ++i) {
      long long product = nums[i];
      if (nums[i] < 0) {
        product *= mn[i + m - 1];
      } else {
        product *= mx[i + m - 1];
      }
      ans = max(ans, product);
    }

    return ans;
  }
};