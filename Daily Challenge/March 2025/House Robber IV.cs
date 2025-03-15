public class Solution {
  public int MinCapability(int[] nums, int k) {
    int left = 1, right = 1000000000;

    while (left <= right) {
      int mid = (left + right) / 2;
      
      if (CanRob(nums, k, mid)) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }

    return left;
  }

  private bool CanRob(int[] nums, int k, int capability) {
    int houses = 0;
    int cnt = 0;

    for (int i = 0; i < nums.Length; ++i) {
      if (nums[i] <= capability) {
        cnt++;
      } else {
        houses += (cnt + 1) / 2;
        cnt = 0;
      }
    }
    houses += (cnt + 1) / 2;

    return houses >= k;
  }
}