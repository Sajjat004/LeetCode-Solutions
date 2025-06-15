class Solution {
  int changeDigit(string s, char from, char to) {
    for (char& c : s) {
      if (c == from) {
        c = to;
      }
    }

    return stoi(s);
  }
public:
  int minMaxDifference(int num) {
    string s = to_string(num);
    int maxValue = num;
    int minValue = num;
    for (char from : s) {
      for (char to = '0'; to <= '9'; ++to) {
        int newValue = changeDigit(s, from, to);
        maxValue = max(maxValue, newValue);
        minValue = min(minValue, newValue);
      }
    }

    return maxValue - minValue;
  }
};