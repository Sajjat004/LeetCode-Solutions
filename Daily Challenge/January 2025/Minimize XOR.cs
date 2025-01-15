public class Solution {
  private int CountBits(int n) {
    int count = 0;
    while (n > 0) {
      count += n & 1;
      n >>= 1;
    }

    return count;
  }
  public int MinimizeXor(int num1, int num2) {
    int setBitsOfNum2 = CountBits(num2);

    int result = 0;
    for (int i = 29; i >= 0; i--) {
      if ((num1 & (1 << i)) != 0) {
        if (setBitsOfNum2 > 0) {
          result |= 1 << i;
          setBitsOfNum2--;
        }
      }
    }

    for (int i = 0; i < 30; ++i) {
      if ((num1 & (1 << i)) == 0) {
        if (setBitsOfNum2 > 0) {
          result |= 1 << i;
          setBitsOfNum2--;
        }
      }
    }

    return result;
  }
}