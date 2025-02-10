public class Solution {
  public bool IsDigit(char c) {
    return c >= '0' && c <= '9';
  }

  public string ClearDigits(string s) {
    int n = s.Length;
    int countDight = 0;
    string result = "";

    for (int i = n - 1; i >= 0; --i) {
      if (IsDigit(s[i])) {
        countDight++;
      } else {
        if (countDight == 0) {
          result += s[i];
        } else {
          countDight--;
        }
      }
    }

    string finalResult = new string(result.Reverse().ToArray());

    return finalResult;
  }
}