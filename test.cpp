class Solution {
  void changeDirection(bool& xPositive, bool& xNegative, bool& yPositive, bool& yNegative, int command) {
    if (xPositive) {
      if (command == -2) yPositive = true;
      else yNegative = true;

      xPositive = false;
    } else if (xNegative) {
      if (command == -2) yNegative = true;
      else yPositive = true;

      xNegative = false;
    } else if (yPositive) {
      if (command == -2) xNegative = true;
      else xPositive = true;

      yPositive = false;
    } else {
      if (command == -2) xPositive = true;
      else xNegative = true;

      yNegative = false;
    }
  }

  void move(bool xPositive, bool xNegative, bool yPositive, bool yNegative, int command, int& x, int& y, map<pair<int, int>, bool>& obstacle) {
    for (int i = 1; i <= command; ++i) {
      if (obstacle[{x + (xPositive ? 1 : xNegative ? -1 : 0), y + (yPositive ? 1 : yNegative ? -1 : 0)}]) break;
      x += (xPositive ? 1 : xNegative ? -1 : 0);
      y += (yPositive ? 1 : yNegative ? -1 : 0);
    }

    return;
  }

public:
  int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
    int x = 0, y = 0;
    bool xPositive = false;
    bool xNegative = false;
    bool yPositive = true;
    bool yNegative = false;

    map<pair<int, int>, bool> obstacle;
    for (auto x : obstacles) {
      obstacle[{x[0], x[1]}] = true;
    }

    int ans = 0;

    for (int command : commands) {
      if (command > 0) {
        move(xPositive, xNegative, yPositive, yNegative, command, x, y, obstacle);
        ans = max(ans, (x * x) + (y * y));
      } else {
        changeDirection(xPositive, xNegative, yPositive, yNegative, command);
      }
    }

    return ans;
  }
};