public class Solution {
  public int CountDays(int days, int[][] meetings) {
    
    meetings = meetings.OrderBy(x => x[0]).ToArray();

    int daysWithoutMeetings = 0;
    int lastMeeting = 0;

    foreach (var meeting in meetings) {
      if (meeting[0] > lastMeeting) {
        daysWithoutMeetings += meeting[0] - lastMeeting - 1;
      }

      lastMeeting = Math.Max(lastMeeting, meeting[1]);
    }
    daysWithoutMeetings += days - lastMeeting;

    return daysWithoutMeetings;
  }
}