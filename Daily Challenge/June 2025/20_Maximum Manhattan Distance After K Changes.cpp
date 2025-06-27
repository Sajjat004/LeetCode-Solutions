class Solution {
public:
  int maxDistance(string s, int k) {
    int maxDistance = 0;
    vector<int> countMove(4, 0);

    for (int i = 0; i < s.size(); ++i) {
      countMove[getMoveIndex(s[i])]++;
      maxDistance = max(maxDistance, solve(countMove, k));
    }

    return maxDistance;
  }

private:

  int solve(vector<int>& countMove, int k) {
    int mx = max(countMove[0], countMove[1]);
    int mn = min(countMove[0], countMove[1]);
    int del = min(mn, k);
    mx += del;
    mn -= del;
    k -= del;
    int result = mx - mn;

    mx = max(countMove[2], countMove[3]);
    mn = min(countMove[2], countMove[3]);
    del = min(mn, k);
    mx += del;
    mn -= del;
    k -= del;
    result += mx - mn;

    return result;
  }

  int getMoveIndex(char ch) {
    if (ch == 'N') return 0;
    if (ch == 'S') return 1;
    if (ch == 'E') return 2;
    if (ch == 'W') return 3;

    return -1;
  }
  
};