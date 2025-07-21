class Solution {
  using ll = long long;
public:
  int mostBooked(int n, vector<vector<int>>& meetings) {
    vector<int> cnt(n, 0);
    priority_queue<int, vector<int>, greater<int>> freeRooms;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> busyRooms;
    ll time = 0;
    for (int i = 0; i < n; ++i) {
      freeRooms.push(i);
    }
    sort(meetings.begin(), meetings.end());
    for (const auto& meeting : meetings) {
      ll start = meeting[0], end = meeting[1];
      time = max(time, start);
      
      while (!busyRooms.empty() && busyRooms.top().first <= time) {
        int room = busyRooms.top().second;
        busyRooms.pop();
        freeRooms.push(room);
      }
      
      if (freeRooms.empty()) {
        auto [nextEnd, room] = busyRooms.top();
        busyRooms.pop();
        time = nextEnd;
        freeRooms.push(room);
      }
      
      int room = freeRooms.top();
      freeRooms.pop();
      cnt[room]++;
      busyRooms.push({time + (end - start), room});
    }
    int maxCount = 0, resultRoom = 0;
    for (int i = 0; i < n; ++i) {
      if (cnt[i] > maxCount) {
        maxCount = cnt[i];
        resultRoom = i;
      }
    }
    return resultRoom;
  }
};