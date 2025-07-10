class Solution {
public:
  int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
    int n = startTime.size();
    int tm = 0;
    vector<int> free;
    for (int i = 0; i < n; ++i) {
      free.push_back(startTime[i] - tm);
      tm = endTime[i];
    }
    free.push_back(eventTime - tm);
    n = free.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      ans = max(ans, free[i]);
    }
    vector<int> mxL(n);
    vector<int> mxR(n);
    int mx = 0;
    for (int i = 0; i < n; ++i) {
      mx = max(mx, free[i]);
      mxL[i] = mx;
    }
    mx = 0;
    for (int i = n - 1; i >= 0; --i) {
      mx = max(mx, free[i]);
      mxR[i] = mx;
    }
    for (int i = 1; i < n; ++i) {
      int diff = endTime[i - 1] - startTime[i - 1];
      if (i < n - 1 and mxR[i + 1] >= diff) ans = max(ans, free[i - 1] + free[i] + diff);
      else if (i - 2 >= 0 and mxL[i - 2] >= diff) ans = max(ans, free[i - 1] + free[i] + diff);
    }
    for (int i = 1; i < n; ++i) {
      free[i] += free[i - 1];
    }
    for (int i = 0; i < n; ++i) {
      int val = free[i];
      if (i - 2 >= 0) val -= free[i - 2];
      ans = max(ans, val);
    }
    return ans;
  }
};