class Solution {
  string changeDigit(int num, int from, int to) {
    string str = to_string(num);
    for (char& c : str) {
      if (c - '0' == from) {
        c = '0' + to;
      }
    }
    return str;
  }

public:
  int maxDiff(int num) {

    int maxNum = num;
    int minNum = num;

    for (int from = 0; from < 10; ++from) {
      for (int to = 0; to < 10; ++to) {
        if (from == to) continue;

        string str = changeDigit(num, from, to);
        if (str[0] != '0') {
          int n = stoi(str);
          maxNum = max(maxNum, n);
          minNum = min(minNum, n);
        }
      }
    }

    return maxNum - minNum;
  }
};