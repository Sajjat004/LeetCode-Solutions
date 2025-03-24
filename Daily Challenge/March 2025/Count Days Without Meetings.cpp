class Solution {
public:
  int countDays(int days, vector<vector<int>>& meetings) {
    sort(meetings.begin(), meetings.end());

    int daysWithoutMeetings = 0;
    int lastDay = 0;

    for (auto meeting : meetings) {
      if (meeting[0] > lastDay) {
        daysWithoutMeetings += meeting[0] - lastDay - 1;
      }
      lastDay = max(lastDay, meeting[1]);
    }
    daysWithoutMeetings += days - lastDay;

    return daysWithoutMeetings;
  }
};