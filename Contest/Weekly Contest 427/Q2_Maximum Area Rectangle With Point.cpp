class Solution {
public:
  int maxRectangleArea(vector<vector<int>>& points) {
    int n = points.size();

    auto isValidRectangle = [&](int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) -> bool {
      if (x1 != x3 || y1 != y2 || x2 != x4 || y3 != y4) return false;
      if (x1 >= x2 || y1 >= y3 || x3 >= x4 || y2 >= y4) return false;
      
      for (auto& point : points) {
        int x = point[0], y = point[1];
        if (x == x1 and y == y1) continue;
        if (x == x2 and y == y2) continue;
        if (x == x3 and y == y3) continue;
        if (x == x4 and y == y4) continue;

        if (x >= x1 and x <= x2 && y >= y1 && y <= y3) return false;
      }

      return true;
    };

    auto area = [&](int x1, int y1, int x4, int y4) -> int {
      return abs(x4 - x1) * abs(y4 - y1);
    };

    int maxArea = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == j) continue;
        for (int k = 0; k < n; ++k) {
          if (k == i || k == j) continue;
          for (int l = 0; l < n; ++l) {
            if (l == i || l == j || l == k) continue;
            int x1 = points[i][0], y1 = points[i][1];
            int x2 = points[j][0], y2 = points[j][1];
            int x3 = points[k][0], y3 = points[k][1];
            int x4 = points[l][0], y4 = points[l][1];

            if (isValidRectangle(x1, y1, x2, y2, x3, y3, x4, y4)) {
              int currentArea = area(x1, y1, x4, y4);
              maxArea = max(maxArea, currentArea);
            }
          }
        }
      }
    }

    return maxArea == 0 ? -1 : maxArea;
  }
};