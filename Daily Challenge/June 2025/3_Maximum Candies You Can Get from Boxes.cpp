class Solution {
public:
  int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
    int n = status.size();
    vector<bool> visited(n, false);
    vector<bool> canOpen(n, false);
    queue<int> q;
    int totalCandies = 0;

  
    for (int box : initialBoxes) {
      if (status[box] == 1) {
        visited[box] = true;
        q.push(box);
      } else {
        canOpen[box] = true;
      }
    }

    while (!q.empty()) {
      int box = q.front();
      q.pop();

      totalCandies += candies[box];
      for (int key : keys[box]) {
        status[key] = 1;
        if (canOpen[key] && !visited[key]) {
          visited[key] = true;
          q.push(key);
        }
      }

      for (int containedBox : containedBoxes[box]) {
        if (!visited[containedBox] && status[containedBox] == 1) {
          visited[containedBox] = true;
          q.push(containedBox);
        } else if (!visited[containedBox]) {
          canOpen[containedBox] = true;
        }
      }
    }

    return totalCandies;
  }
};