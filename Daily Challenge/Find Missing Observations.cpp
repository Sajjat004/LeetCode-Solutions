// Challenge Date: 05 Sep, 2024

class Solution {
public:
  vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
    int rollingSum = 0;
    int m = rolls.size();

    for (int value : rolls) {
      rollingSum += value;
    }

    int need = -1;
    // check possible needed value
    for (int i = n; i <= 6 * n; ++i) {
      if ((i + rollingSum) == (mean) * (m + n)) {
        need = i;
        break;
      }
    }

    vector<int> ans;
    if (need != -1) {
      int x = need / n;
      need %= n;
      ans.assign(n, x);
      for (int& x : ans) {
        if (need) {
          x++;
          need--;
        }
      }
    }

    return ans;
  }
};