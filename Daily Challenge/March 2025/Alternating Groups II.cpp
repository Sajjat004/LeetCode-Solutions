class Solution {
public:
  int numberOfAlternatingGroups(vector<int>& colors, int k) {
    int n = colors.size();
    for (int i = 0; i < n; i++) {
      colors.push_back(colors[i]);
    }

    int left = 0, groups = 0;
    for (int i = 1; i < n + k - 1; ++i) {
      if (colors[i] == colors[i - 1]) {
        if (i - left >= k) groups += (i - left - k + 1);
        left = i;
      }
    }

    if (n + k - 1 - left >= k) groups += (n + k - 1 - left - k + 1);

    return groups;
  }
};