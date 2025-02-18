public class Solution {
  public string SmallestNumber(string pattern) {
    int n = pattern.Length;
    Stack<int> stack = new Stack<int>();
    StringBuilder sb = new StringBuilder();

    for (int index = 0; index <= n; index++) {
      stack.Push(index + 1);

      if (index == n || pattern[index] == 'I') {
        while (stack.Count > 0) {
          sb.Append(stack.Pop());
        }
      }
    }

    return sb.ToString();
  }
}