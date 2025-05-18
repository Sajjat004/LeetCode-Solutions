class Solution {
  const int mod = 1e9 + 7;
  int stateMemo[1002][1024];
  int n, m;

  int countWays(int row, int col, int preState, int curSate) {
    if (col == n) return 1;
    if (row == m) return countWays(0, col + 1, curSate, 0);
    if (row == 0 and stateMemo[col][preState] != -1) return stateMemo[col][preState];

    int upColor = curSate & 3;
    int leftColor = (preState >> (m - row - 1) * 2) & 3;
    int waysOfColor = 0;
    for (int color = 1; color <= 3; ++color) {
      if (color != upColor && color != leftColor) {
        waysOfColor = (waysOfColor + countWays(row + 1, col, preState, (curSate << 2) | color)) % mod;
      }
    }

    if (row == 0) stateMemo[col][preState] = waysOfColor;

    return waysOfColor;
  }
public:
  int colorTheGrid(int m, int n) {
    this->m = m;
    this->n = n;
    memset(stateMemo, -1, sizeof(stateMemo));
    
    return countWays(0, 0, 0, 0);
  }
};