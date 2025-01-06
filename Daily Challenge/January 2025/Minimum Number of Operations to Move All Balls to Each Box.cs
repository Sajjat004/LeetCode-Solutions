public class Solution {
  public int[] MinOperations(string boxes) {
    int n = boxes.Length;

    int[] left = new int[n];
    int[] right = new int[n];
    int count = 0;
    int operations = 0;
    for (int i = 0; i < n; i++) {
      operations += count;
      left[i] = operations;
      count += boxes[i] - '0';
    }

    count = 0;
    operations = 0;
    for (int i = n - 1; i >= 0; i--) {
      operations += count;
      right[i] = operations;
      count += boxes[i] - '0';
    }

    int[] result = new int[n];
    for (int i = 0; i < n; i++) {
      result[i] = left[i] + right[i];
    }

    return result;
  }
}