class Solution {
  int countSetBits(int n) {
    int count = 0;
    while (n) {
      count += n & 1;
      n >>= 1;
    }

    return count;
  }
  
public:
  int minimizeXor(int num1, int num2) {
    int setBitsOfnum2 = countSetBits(num2);
    int result = 0;

    for (int i = 29; i >= 0; --i) {
      if (num1 & (1 << i)) {
        if (setBitsOfnum2) {
          result += 1 << i;
          setBitsOfnum2--;
        }
      }
    }

    for (int i = 0; i < 30; ++i) {
      if (!(num1 & (1 << i))) {
        if (setBitsOfnum2) {
          result += 1 << i;
          setBitsOfnum2--;
        }
      }
    }

    return result;
  }
};