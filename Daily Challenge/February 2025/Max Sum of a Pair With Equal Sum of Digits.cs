public class Solution {
  public int MaximumSum(int[] nums) {
    Dictionary<int, int> digitSumToMaxValue = new Dictionary<int, int>();
    int result = -1;

    foreach (int x in nums) {
      int digitSum = GetDigitSum(x);

      if (digitSumToMaxValue.ContainsKey(digitSum)) {
        result = Math.Max(result, digitSumToMaxValue[digitSum] + x);
        digitSumToMaxValue[digitSum] = Math.Max(digitSumToMaxValue[digitSum], x);
      } else {
        digitSumToMaxValue[digitSum] = x;
      }
    }

    return result;
  }

  private int GetDigitSum(int x) {
    int sum = 0;

    while (x > 0) {
      sum += x % 10;
      x /= 10;
    }

    return sum;
  }
}