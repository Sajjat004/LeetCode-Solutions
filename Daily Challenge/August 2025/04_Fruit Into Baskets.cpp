class Solution {
public:
  int totalFruit(vector<int>& fruits) {
    int n = fruits.size();
    int res = 0;
    vector<int> type(n, 0);
    int cntFruit = 0, cntType = 0;
    for (int l = 0, r = 0; l < n; ++l) {
      while (r < n && (cntType < 2 || (cntType == 2 && type[fruits[r]] > 0))) {
        if (type[fruits[r]] == 0) {
          cntType++;
        }
        type[fruits[r]]++;
        r++;
      }
      res = max(res, r - l);
      type[fruits[l]]--;
      if (type[fruits[l]] == 0) {
        cntType--;
      }
    }
    return res;
  }
};