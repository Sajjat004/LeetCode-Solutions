class Solution {
public:
  int maximumGain(string s, int x, int y) {
    int n = s.size();
    
    auto score = [&](char p, char q, int val) -> int {
      int cnt = 0;
      stack<pair<char, int>> st;
      for (int i = 0; i < n; ++i) {
        if (s[i] == '#') continue;
        if (s[i] == q && !st.empty() && st.top().first == p) {
          cnt++;
          s[st.top().second] = '#';
          s[i] = '#';
          st.pop();
        } else {
          st.push({s[i], i});
        }
      }
      return cnt * val;
    };

    int res = 0;
    if (x > y) {
      res += score('a', 'b', x);
      res += score('b', 'a', y);
    } else {
      res += score('b', 'a', y);
      res += score('a', 'b', x);
    }
    return res;
  }
};