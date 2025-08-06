class Solution {
public:
  int subarrayBitwiseORs(vector<int>& arr) {
    unordered_set<int> res, cur;
    for (int x : arr) {
      unordered_set<int> next;
      next.insert(x);
      for (int y : cur) {
        next.insert(x | y);
      }
      cur = move(next);
      res.insert(cur.begin(), cur.end());
    }
    return res.size();
  }
};