class Solution {
public:
  int minCapability(vector<int>& nums, int k) {
    int left = 1, right = 1e9;

    while (left <= right) {
      int mid = (left + right) / 2;
      if (isPossible(nums, k, mid)) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }

    return left;
  }

private:
  bool isPossible(vector<int>& nums, int k, int mid) {
    int count = 0, houses = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] <= mid) {
        count++;
      } else {
        if (count > 0) {
          houses += (count + 1) / 2;
        }
        count = 0;
      }
    }
    if (count > 0) {
      houses += (count + 1) / 2;
    }

    return houses >= k;
  }
};