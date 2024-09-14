// Challenge Date: 13 Sep, 2024
class Solution {
public:
  vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    int n = arr.size();

    vector<int> XOR(n);
    XOR[0] = arr[0];
    for (int i = 1; i < n; ++i) {
      XOR[i] = XOR[i - 1] ^ arr[i];
    }

    vector<int> answer;
    for (auto query: queries) {
      int l = query[0];
      int r = query[1];
      int ans = XOR[r];
      if (l > 0) ans ^= XOR[l - 1];
      answer.push_back(ans);
    }

    return answer;
  }
};