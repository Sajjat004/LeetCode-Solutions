class Solution {
using ll = long long;
public:
  ll kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, ll k) {
    int n = nums1.size(), m = nums2.size();

    auto fun = [&] (ll mx, ll x) ->ll {
      if (x * nums2[0] > mx) return 0;
      int left = 0, right = m - 1;
      while (left < right) {
        int mid = left + (right - left + 1) / 2;
        if (x * nums2[mid] <= mx) {
          left = mid;
        } else {
          right = mid - 1;
        }
      }
      return left + 1;
    };

    auto fun2 = [&] (ll mx, ll x) ->ll {
      if (x * nums2[m - 1] > mx) return 0;
      int left = 0, right = m - 1;
      while (left < right) {
        int mid = left + (right - left) / 2;
        if (x * nums2[mid] <= mx) {
          right = mid;
        } else {
          left = mid + 1;
        }
      }
      return m - right;
    };

    ll left = -1e10, right = 1e10;
    while (left < right) {
      ll mid = left + (right - left) / 2;
      ll cnt = 0;

      for (int i = 0; i < n; ++i) {
        if (nums1[i] > 0) {
          cnt += fun(mid, nums1[i]);
        } else if (nums1[i] < 0) {
          cnt += fun2(mid, nums1[i]);
        } else {
          if (mid >= 0) {
            cnt += m;
          }
        }
      }
      
      if (cnt < k) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }

    return left;
  }
};