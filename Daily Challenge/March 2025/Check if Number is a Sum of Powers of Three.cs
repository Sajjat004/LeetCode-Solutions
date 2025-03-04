public class Solution {
  public bool CheckPowersOfThree(int n) {
    List<int> powersOfThree = new List<int>();
    int value = 1;
    powersOfThree.Add(value);

    while (value < n) {
      value *= 3;
      powersOfThree.Add(value);
    }

    for (int i = powersOfThree.Count - 1; i >= 0; i--) {
      if (n >= powersOfThree[i]) {
        n -= powersOfThree[i];
      }
    }

    return n == 0;
  }
}