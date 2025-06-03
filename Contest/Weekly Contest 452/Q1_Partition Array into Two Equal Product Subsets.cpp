#include <vector>
using namespace std;

class Solution {
public:
  bool checkEqualPartitions(vector<int>& nums, long long target) {
    int n = nums.size();

    for (int x = 0; x < (1 << n); x++) {
      __int128 prod1 = 1;
      __int128 prod2 = 1;
      for (int j = 0; j < n; j++) {
        if (x & (1 << j)) {
          prod1 *= nums[j];
        } else {
          prod2 *= nums[j];
        }
      }

      if (prod1 == target && prod2 == target) return true;
    }

    return false;
  }
};