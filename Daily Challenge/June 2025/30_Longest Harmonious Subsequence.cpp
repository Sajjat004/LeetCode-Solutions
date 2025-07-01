class Solution {
public:
  int findLHS(vector<int>& nums) {
    map<int, int> freq;
    for (int num : nums) {
      freq[num]++;
    }

    int mxLen = 0;
    for (int num : nums) {
      if (freq.count(num + 1)) {
        mxLen = max(mxLen, freq[num] + freq[num + 1]);
      }
    }
    return mxLen;
  }
};