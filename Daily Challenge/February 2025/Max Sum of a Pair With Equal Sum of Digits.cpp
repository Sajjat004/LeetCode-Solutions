class Solution {
public:
  int maximumSum(vector<int>& nums) {
    unordered_map<int, int> digitSumOfValue;
    int res = -1;

    for (int x : nums) {
      int digitSum = this->digitSum(x);
      if (digitSumOfValue.count(digitSum)) {
        res = max(res, digitSumOfValue[digitSum] + x);
        digitSumOfValue[digitSum] = max(digitSumOfValue[digitSum], x);
      } else {
        digitSumOfValue[digitSum] = x;
      }
    }

    return res;
  }

private:
  int digitSum(int x) {
    int sum = 0;
    while (x) {
      sum += x % 10;
      x /= 10;
    }

    return sum;
  }
};