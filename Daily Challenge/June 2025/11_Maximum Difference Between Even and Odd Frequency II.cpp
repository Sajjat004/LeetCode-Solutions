class Solution {
public:
  int maxDifference(string s, int k) {
    auto getStatus = [](int cntA, int cntB) -> int {
      return ((cntA & 1) << 1) | (cntB & 1);
    };

    int n = s.size();
    int ans = INT_MIN;

    for (int a = 0; a <= 4; ++a) {
      for (int b = 0; b <= 4; ++b) {
        if (a == b) continue;

        int best[4] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX};
        int cntA = 0, cntB = 0;
        int prevA = 0, prevB = 0;
        int left = -1;

        for (int right = 0; right < n; ++right) {
          cntA += (s[right] - '0' == a);
          cntB += (s[right] - '0' == b);

          while (right - left >= k && cntB - prevB >= 2) {
            int leftStatus = getStatus(prevA, prevB);
            best[leftStatus] = min(best[leftStatus], prevA - prevB);
            ++left;
            prevA += (s[left] - '0' == a);
            prevB += (s[left] - '0' == b);
          }

          int rightStatus = getStatus(cntA, cntB);
          if (best[rightStatus ^ 0b10] != INT_MAX) {
            ans = max(ans, cntA - cntB - best[rightStatus ^ 0b10]);
          }
        }
      }
    }

    return ans;
  }
};