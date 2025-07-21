class Solution {
  using ll = long long;
public:
  long long minimumDifference(vector<int>& nums) {
    int n = nums.size() / 3;
    vector<ll> left(3 * n, 0), right(3 * n, 0);
    priority_queue<ll> pq;
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
      pq.push(nums[i]);
      sum += nums[i];
    }
    left[n - 1] = sum;
    for (int i = n; i < 2 * n; ++i) {
      if (nums[i] < pq.top()) {
        sum -= pq.top();
        pq.pop();
        pq.push(nums[i]);
        sum += nums[i];
      }
      left[i] = sum;
    }

    priority_queue<ll, vector<ll>, greater<ll>> pq1;
    sum = 0;
    for (int i = 3 * n - 1; i >= 2 * n; --i) {
      pq1.push(nums[i]);
      sum += nums[i];
    }
    right[2 * n] = sum;
    for (int i = 2 * n - 1; i >= n; --i) {
      if (nums[i] > pq1.top()) {
        sum -= pq1.top();
        pq1.pop();
        pq1.push(nums[i]);
        sum += nums[i];
      }
      right[i] = sum;
    }
    ll ans = LLONG_MAX;
    for (int i = n - 1; i < 2 * n; ++i) {
      ans = min(ans, left[i] - right[i + 1]);
    }

    return ans;
  }
};