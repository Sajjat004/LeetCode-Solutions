class Solution {
public:
  int findNumbers(vector<int>& nums) {
    int countEvenDigitNum = 0;

    auto digitCount = [&](int num) {
      int count = 0;

      while (num > 0) {
        count++;
        num /= 10;
      }

      return count;
    };

    for (int num : nums) {
      if (digitCount(num) % 2 == 0) {
        countEvenDigitNum++;
      }
    }

    return countEvenDigitNum;
  }
};