class Solution {
public:
  int maximumLength(vector<int>& nums) {
    int cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
    for (int n : nums) {
      if (n % 2 == 0) cnt1++;
      else cnt2++;
    }
    bool flag = false;
    bool flag2 = false;
    for (int n : nums) {
      if (!flag && n % 2 == 0) {
        cnt3++;
        flag = true;
      } else if (flag && n % 2 == 1) {
        cnt3++;
        flag = false;
      }

      if (!flag2 && n % 2 == 1) {
        cnt4++;
        flag2 = true;
      } else if (flag2 && n % 2 == 0) {
        cnt4++;
        flag2 = false;
      }
    }
    return max({cnt1, cnt2, cnt3, cnt4});
  }
};