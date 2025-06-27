class Solution {
public:
  string longestSubsequenceRepeatedK(string s, int k) {
    vector<int> freq(26, 0);
    for (char c : s) {
      freq[c - 'a']++;
    }

    vector<char> candi;
    for (int i = 25; i >= 0; --i) {
      if (freq[i] >= k) {
        candi.push_back('a' + i);
      }
    }

    queue<string> q;
    for (char c : candi) {
      q.push(string(1, c));
    }
    string ans = "";
    while (!q.empty()) {
      string cur = q.front();
      q.pop();
      if (cur.size() > ans.size()) {
        ans = cur;
      }
      for (char c : candi) {
        string next = cur + c;
        if (valid(s, next, k)) {
          q.push(next);
        }
      }
    }

    return ans;
  }

private:
  bool valid(const string& s, const string& t, int k) {
    int n = s.size();
    int m = t.size();
    for (int i = 0, j = 0; i < n; ++i) {
      if (s[i] == t[j]) {
        j++;
        if (j == m) k--;
        if (k == 0) return true;
        j %= m;
      }
    }
    return false;
  }
};