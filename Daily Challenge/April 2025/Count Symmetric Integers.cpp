class Solution {
public:
  int countSymmetricIntegers(int low, int high) {
    int count = 0;
    for (int i = low; i <= high; ++i) {
      if (isSymmetric(i)) {
        count++;
      }
    }
    
    return count;
  }

private:
  bool isSymmetric(int n) {
    string s = to_string(n);
    int len = s.length();
    if (len % 2 != 0) return false;
    int mid = len / 2;
    int leftSum = 0, rightSum = 0;

    for (int i = 0; i < mid; ++i) {
      leftSum += s[i] - '0';
      rightSum += s[i + mid] - '0';
    }

    return leftSum == rightSum;
  }
};