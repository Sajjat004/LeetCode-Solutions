class Solution {
public:
  int longestSubsequence(string s, int k) {
    int n = s.size();
    int mxLen = 0;
    for (int i = 0; i < n; ++i) {
      int num = 0, len = 0;
      for (int j = i; j >= 0; --j) {
        if (s[j] == '0') {
          len++;
        } else if (len < 31 and (num + (1 << len)) <= k) {
          num += (1 << len);
          len++;
        }
      }
      mxLen = max(mxLen, len);
    }
    
    return mxLen;
  }
};