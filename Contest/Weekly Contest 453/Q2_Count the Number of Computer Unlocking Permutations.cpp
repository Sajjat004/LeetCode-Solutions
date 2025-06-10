class Solution {
public:
  int countPermutations(vector<int>& complexity) {
    int n = complexity.size();
    int mn = INT_MAX;
    for (int i = 0; i < n; ++i) {
      mn = min(mn, complexity[i]);
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (complexity[i] == mn) {
        ++cnt;
      }
    }
    
    if (cnt > 1 or complexity[0] != mn) {
      return 0;
    }

    int ans = 1;
    for (int i = 1; i < n; ++i) {
      ans = (1LL * ans * i) % 1000000007;
    }

    return ans;
  }
};