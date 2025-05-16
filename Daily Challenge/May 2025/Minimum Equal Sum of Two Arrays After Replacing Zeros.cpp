class Solution {
public:
  long long minSum(vector<int>& nums1, vector<int>& nums2) {
    long long sum1 = 0, sum2 = 0;
    int countZeros1 = 0, countZeros2 = 0;

    for (int num : nums1) {
      sum1 += num;
      if (num == 0) countZeros1++;
    }

    for (int num : nums2) {
      sum2 += num;
      if (num == 0) countZeros2++;
    }

    if (countZeros1 == 0 and countZeros2 == 0 and sum1 != sum2) return -1;
    if (countZeros1 == 0 and countZeros2 == 0 and sum1 == sum2) return sum1;

    sum1 += countZeros1;
    sum2 += countZeros2;

    if (sum1 == sum2) return sum1;
    if (sum1 > sum2 and countZeros2 > 0) return sum1;
    if (sum1 < sum2 and countZeros1 > 0) return sum2;

    return -1;
  }
};