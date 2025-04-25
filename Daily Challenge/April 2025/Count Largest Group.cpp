class Solution {
public:
  int countLargestGroup(int n) {
    vector<int> groupCount(46, 0); 

    for (int i = 1; i <= n; ++i) {
      int sum = digitSum(i);
      groupCount[sum]++;
    }
    
    int maxCount = *max_element(groupCount.begin(), groupCount.end());

    return count(groupCount.begin(), groupCount.end(), maxCount);
  }

private:
  int digitSum(int n) {
    int sum = 0;
    while (n > 0) {
      sum += n % 10;
      n /= 10;
    }
    return sum;
  }
};