class Solution {
public:
  bool checkPowersOfThree(int n) {
    vector<int> powersOfThree;
    int value = 1;
    powersOfThree.push_back(value);
    while (value < n) {
      value *= 3;
      powersOfThree.push_back(value);
    }

    for (int i = powersOfThree.size() - 1; i >= 0; i--) {
      if (n >= powersOfThree[i]) {
        n -= powersOfThree[i];
      }
    }

    return n == 0;
  }
};