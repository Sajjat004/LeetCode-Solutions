class Solution {
public:
  vector<int> queryResults(int limit, vector<vector<int>>& queries) {
    unordered_map<int, int> colorMap;
    unordered_map<int, int> balls;
    vector<int> result;
    int distinctColors = 0;

    for (auto& query : queries) {
      int ballIndex = query[0];
      int ballColor = query[1];

      if (balls[ballIndex] == 0) {
        balls[ballIndex] = ballColor;
        colorMap[ballColor]++;
        if (colorMap[ballColor] == 1) distinctColors++;
      } else {
        colorMap[balls[ballIndex]]--;
        if (colorMap[balls[ballIndex]] == 0) distinctColors--;
        balls[ballIndex] = ballColor;
        colorMap[ballColor]++;
        if (colorMap[ballColor] == 1) distinctColors++;
      }

      result.push_back(distinctColors);
    }

    return result;
  }
};