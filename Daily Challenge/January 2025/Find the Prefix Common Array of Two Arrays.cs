public class Solution {
  public int[] FindThePrefixCommonArray(int[] A, int[] B) {
    int n = A.Length;
    bool[] markA = new bool[n + 1];
    bool[] markB = new bool[n + 1];
    int counter = 0;
    int[] result = new int[n];

    for (int i = 0; i < n; ++i) {
      if (markA[B[i]]) counter++;
      markB[B[i]] = true;
      if (markB[A[i]]) counter++;
      markA[A[i]] = true;

      result[i] = counter;
    }

    return result;
  }
}