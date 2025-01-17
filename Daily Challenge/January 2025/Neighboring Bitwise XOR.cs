public class Solution {
  public bool DoesValidArrayExist(int[] derived) {
    int XOR = 0;
    foreach (int num in derived) {
      XOR ^= num;
    }

    return XOR == 0;
  }
}