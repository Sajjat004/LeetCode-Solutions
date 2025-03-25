class Solution {
public:
  bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
    int m = rectangles.size();

    vector<pair<int, int>> horizontalLines;
    vector<pair<int, int>> verticalLines;

    for (auto& rectangle : rectangles) {
      int x1 = rectangle[0];
      int y1 = rectangle[1];
      int x2 = rectangle[2];
      int y2 = rectangle[3];

      horizontalLines.push_back({y1, y2});
      verticalLines.push_back({x1, x2});
    }

    
    

    // horizontal cuts
    sort(horizontalLines.begin(), horizontalLines.end());
    int firstCut = horizontalLines[0].second;

    for (int i = 1; i < m; ++i) {
      if (horizontalLines[i].first < firstCut) {
        firstCut = max(firstCut, horizontalLines[i].second);
      } else if (horizontalLines[i].first > firstCut) {
        break;
      }
    }

    sort(horizontalLines.begin(), horizontalLines.end(), [&](pair<int, int>& a, pair<int, int>& b) {
      if (a.second == b.second) return a.first > b.first;
      return a.second < b.second;
    });
    int lastCut = horizontalLines[m - 1].first;

    for (int i = m- 2; i >= 0; --i) {
      if (horizontalLines[i].second > lastCut) {
        lastCut = min(lastCut, horizontalLines[i].first);
      } else if (horizontalLines[i].second < lastCut) {
        break;
      }
    }

    for (int i = 0; i < m; ++i) {
      if (firstCut < lastCut && horizontalLines[i].first >= firstCut && horizontalLines[i].second <= lastCut) {
        return true;
      }
    }

    // vertical cuts
    sort(verticalLines.begin(), verticalLines.end());
    firstCut = verticalLines[0].second;

    for (int i = 1; i < m; ++i) {
      if (verticalLines[i].first < firstCut) {
        firstCut = max(firstCut, verticalLines[i].second);
      } else if (verticalLines[i].first > firstCut) {
        break;
      }
    }

    sort(verticalLines.begin(), verticalLines.end(), [&](pair<int, int>& a, pair<int, int>& b) {
      if (a.second == b.second) return a.first > b.first;
      return a.second < b.second;
    });
    lastCut = verticalLines[m - 1].first;

    for (int i = m - 2; i >= 0; --i) {
      if (verticalLines[i].second > lastCut) {
        lastCut = min(lastCut, verticalLines[i].first);
      } else if (verticalLines[i].second < lastCut) {
        break;
      }
    }

    for (int i = 0; i < m; ++i) {
      if (firstCut < lastCut && verticalLines[i].first >= firstCut && verticalLines[i].second <= lastCut) {
        return true;
      }
    }

    return false;
  }
};