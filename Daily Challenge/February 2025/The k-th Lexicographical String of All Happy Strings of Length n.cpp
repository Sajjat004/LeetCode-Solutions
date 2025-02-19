class Solution {
  public:
    string getHappyString(int n, int k) {
      string s = "", ans = "";
      backtrack(s, n, k, ans);
      
      return ans;
    }

  private:
    void backtrack(string &s, int n, int &k, string &ans) {
      if (s.size() == n) {
        if (--k == 0) {
          ans = s;
        }
        return;
      }

      for (char c = 'a'; c <= 'c'; ++c) {
        if (s.empty() || s.back() != c) {
          s.push_back(c);
          backtrack(s, n, k, ans);
          s.pop_back();
        }
      }
    }
  };