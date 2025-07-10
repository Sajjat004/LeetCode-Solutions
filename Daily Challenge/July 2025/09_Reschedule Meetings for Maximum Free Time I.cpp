class Solution {
public:
  int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
    int timer = 0;
    vector<int> freeTime;
    int n = startTime.size();
    for (int i = 0; i < n; ++i) {
      int diff = startTime[i] - timer;
      freeTime.push_back(diff);
      timer = endTime[i];
    }
    int diff = eventTime - timer;
    freeTime.push_back(diff);
    for (int i = 1; i < freeTime.size(); ++i) {
      freeTime[i] += freeTime[i - 1];
    }
    int ans = 0;
    for (int i = 0; i < freeTime.size(); ++i) {
      int val = freeTime[i];
      int l = i - k - 1;
      if (l >= 0) val -= freeTime[l];
      ans = max(ans, val);
    }
    return ans;
  }
};