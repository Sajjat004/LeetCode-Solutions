class Solution {
public:
  int specialTriplets(vector<int>& nums) {
    int n = nums.size();
    map<int, int> count;
    vector<int> left(n, 0), right(n, 0);
    for (int i = 0; i < n; ++i) {
      left[i] = count[2 * nums[i]];
      count[nums[i]]++;
    }
    count.clear();
    for (int i = n - 1; i >= 0; --i) {
      right[i] = count[2 * nums[i]];
      count[nums[i]]++;
    }

    int result = 0;
    for (int i = 1; i < n - 1; ++i) {
      result += (1LL * left[i] * right[i]) % 1000000007;
      result %= 1000000007;
    }

    return result;
  }
};