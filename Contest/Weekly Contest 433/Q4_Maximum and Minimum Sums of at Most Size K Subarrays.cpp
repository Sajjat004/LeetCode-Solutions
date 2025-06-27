class Solution {
  const int mod = 1e9 + 7;

  long long getSum(int n) {
    return (1LL * n * (n + 1) / 2);
  }

  long long getSum(int l, int r) {
    if (l > r) return 0;
    return (getSum(r) - getSum(l - 1));
  }

public:
  long long minMaxSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    stack<int> indexStack;
    stack<int> indexStack1;
    vector<int> leftMinIndex(n, -1), rightMinIndex(n, n);
    vector<int> leftMaxIndex(n, -1), rightMaxIndex(n, n);
    for (int i = n - 1; i >= 0; --i) {
      while (!indexStack.empty() && nums[i] <= nums[indexStack.top()]) {
        indexStack.pop();
      }
      if (!indexStack.empty()) rightMinIndex[i] = indexStack.top();
      indexStack.push(i);

      while (!indexStack1.empty() && nums[i] >= nums[indexStack1.top()]) {
        indexStack1.pop();
      }
      if (!indexStack1.empty()) rightMaxIndex[i] = indexStack1.top();
      indexStack1.push(i);
    }

    indexStack = stack<int>();
    indexStack1 = stack<int>();
    for (int i = 0; i < n; ++i) {
      while (!indexStack.empty() && nums[i] < nums[indexStack.top()]) {
        indexStack.pop();
      }
      if (!indexStack.empty()) leftMinIndex[i] = indexStack.top();
      indexStack.push(i);

      while (!indexStack1.empty() && nums[i] > nums[indexStack1.top()]) {
        indexStack1.pop();
      }
      if (!indexStack1.empty()) leftMaxIndex[i] = indexStack1.top();
      indexStack1.push(i);
    }

    auto contributions = [&] (int mn, int mx, int k) {
      long long sum = getSum(1, mn);
      sum += (1LL * mn * (mx - mn));
      int element = min(k, mx + mn - 1) - mx;
      sum += getSum(mn - element, mn - 1);

      return sum;
    };

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      int lMinCnt = min(k, i - leftMinIndex[i]);
      int rMinCnt = min(k, rightMinIndex[i] - i);
      int lMaxCnt = min(k, i - leftMaxIndex[i]);
      int rMaxCnt = min(k, rightMaxIndex[i] - i);

      int mn = min(lMinCnt, rMinCnt);
      int mx = max(lMinCnt, rMinCnt);
      ans += (1LL * nums[i] * contributions(mn, mx, k));

      mn = min(lMaxCnt, rMaxCnt);
      mx = max(lMaxCnt, rMaxCnt);
      ans += (1LL * nums[i] * contributions(mn, mx, k));
    }

    return ans;
  }
};