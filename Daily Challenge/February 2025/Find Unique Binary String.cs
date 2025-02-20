public class Solution {
  public string FindDifferentBinaryString(string[] nums) {
    bool[] seen = new bool[1 << nums.Length];
    foreach (string num in nums) {
      seen[BinaryToDecimal(num)] = true;
    }

    for (int i = 0; i < (1 << nums.Length); i++) {
      if (!seen[i]) return DecimalToBinary(i, nums.Length);
    }

    return "";
  }

  private int BinaryToDecimal(string binary) {
    int deci = 0;
    for (int i = binary.Length - 1; i >= 0; i--) {
      if (binary[i] == '1') deci += (1 << (binary.Length - 1 - i));
    }

    return deci;
  }

  private string DecimalToBinary(int deci, int length) {
    string binary = "";
    for (int i = 0; i < length; i++) {
      binary = (deci % 2) + binary;
      deci = deci / 2;
    }

    return binary;
  }
}