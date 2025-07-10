class Solution {
public:
  int possibleStringCount(string word) {
    int cnt = 1, ans = 0, n = word.size(), seg = 0;
    for (int i = 1; i < n; ++i) {
      if (word[i] == word[i - 1]) {
        cnt++;
      } else {
        if (cnt > 1) {
          ans += cnt;
          seg++;
        }
        cnt = 1;
      }
    }
    if (cnt > 1) {
      ans += cnt;
      seg++;
    }
    return ans - seg + 1;
  }
};