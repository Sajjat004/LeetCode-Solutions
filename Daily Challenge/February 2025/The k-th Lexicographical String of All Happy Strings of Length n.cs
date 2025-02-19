public class Solution {
  public string GetHappyString(int n, int k) {
    string current = "";
    Backtrack(n, ref k, current);

    return _result;
  }

  private string _result = "";

  private void Backtrack(int n, ref int k, string current) {
    if (current.Length == n) {
      k--;
      if (k == 0) {
        _result = current;
      }
    } else {
      for (char c = 'a'; c <= 'c'; c++) {
        if (current.Length == 0 || current[current.Length - 1] != c) {
          Backtrack(n, ref k, current + c);
        }
      }
    }
  }
}