class Solution {
public:
  string findDifferentBinaryString(vector<string>& nums) {
    vector<bool> seen(1 << nums.size(), false);

    for (string num : nums) {
      seen[binaryToDecimal(num)] = true;
    }

    for (int i = 0; i < (1 << nums.size()); ++i) {
      if (!seen[i]) return decimalToBinary(i, nums.size());
    }

    return "";
  }

private:
  int binaryToDecimal(string binary) {
    int decimal = 0;
  
    int length = binary.length();
    for (int i = length - 1; i >= 0; i--) {
      if (binary[i] == '1') decimal += (1 << (length - i - 1));
    
    }

    return decimal;
  }

  string decimalToBinary(int decimal, int length) {
    string binary = "";
  
    for (int i = 0; i < length; i++) {
      binary = to_string(decimal % 2) + binary;
      decimal /= 2;
    }

    return binary;
  }
};