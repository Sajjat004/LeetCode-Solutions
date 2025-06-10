class Solution {
public:
  string clearStars(string s) {
    int n = s.size();
    vector<bool> keep(n, true);

    auto cmp = [](const pair<char, int>& a, const pair<char, int>& b) {
      if (a.first == b.first) {
        return a.second < b.second;
      } else {
        return a.first > b.first;
      }
    };

    priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> pq(cmp);
    for (int i = 0; i < n; ++i) {
      if (s[i] == '*') {
        keep[i] = false;
        if (!pq.empty()) {
          keep[pq.top().second] = false;
          pq.pop();
        }
      } else {
        pq.push({s[i], i});
      }
    }

    string result = "";
    for (int i = 0; i < n; ++i) {
      if (keep[i]) {
        result += s[i];
      }
    }

    return result;
  }
};