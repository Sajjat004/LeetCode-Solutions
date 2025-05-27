class Solution {
  bool isAdjacent(char a, char b) {
    return abs(a - b) == 1 or abs(a - b) == 25;
  }

public:
  string lexicographicallySmallestString(string s) {
    int n = s.size();
    vector<vector<bool>> deletable(n + 1, vector<bool>(n + 1, false));
    for (int i = 0; i + 1 < n; ++i) {
      if (isAdjacent(s[i], s[i + 1])) {
        deletable[i][i + 1] = true;
      }
    }

    for (int len = 3; len <= n; ++len) {
      for (int i = 0; i + len - 1 < n; ++i) {
        int j = i + len - 1;
        if (isAdjacent(s[i], s[j]) and deletable[i + 1][j - 1]) {
          deletable[i][j] = true;
          continue;
        }

        for (int k = i + 1; k < j; ++k) {
          if (deletable[i][k] and deletable[k + 1][j]) {
            deletable[i][j] = true;
            break;
          }
        }
      }
    }

    vector<string> suffixMin(n + 1);
    suffixMin[n] = "";

    for (int i = n - 1; i >= 0; --i) {
      suffixMin[i] = s[i] + suffixMin[i + 1];
      for (int j = i + 1; j < n; ++j) {
        if (deletable[i][j]) {
          suffixMin[i] = min(suffixMin[i], suffixMin[j + 1]);
        }
      }
    }

    return suffixMin[0];
  }
};