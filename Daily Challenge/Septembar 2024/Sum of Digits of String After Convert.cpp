// Challenge Date: 03 Sep, 2024
class Solution {
  int digitSum(int n) {
    int sum = 0;
    while (n) {
      sum += n % 10;
      n /= 10;
    }

    return sum;
  }
public:
  int getLucky(string s, int k) {
    int sum = 0;
    for (char ch: s) {
      sum += digitSum(ch - 'a' + 1);
    }
    k--;

    while (k--) {
      sum = digitSum(sum);
    }

    return sum;
  }
};