class Solution {
  const int N = 1e5 + 10;
public:
  int maxEvents(vector<vector<int>>& events) {
    vector<vector<int>> staEve(N, vector<int>());
    int n = events.size();
    for (int i = 0; i < n; i++) {
      staEve[events[i][0]].push_back(i);
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int cntEve = 0;
    for (int i = 1; i < N; ++i) {
      for (int j : staEve[i]) {
        pq.push({events[j][1], j});
      }
      while (!pq.empty() && pq.top().first < i) {
        pq.pop();
      }
      if (!pq.empty()) {
        cntEve++;
        pq.pop();
      }
    }
    return cntEve;
  }
};