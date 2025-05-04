class Solution {
public:
  int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    map<pair<int, int>, int> dominoCount;
    int count = 0;

    for (const auto& domino : dominoes) {
      int a = min(domino[0], domino[1]);
      int b = max(domino[0], domino[1]);
      count += dominoCount[{a, b}]++;
    }

    return count;
  }
};