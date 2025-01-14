class Solution {
public:
  vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
    int n = A.size();
    vector<bool> markA(n + 1, false);
    vector<bool> markB(n + 1, false);
    int counter = 0;
    vector<int> ans(n, 0);

    for (int i = 0; i < n; ++i) {
      if (markA[B[i]]) counter++;
      markB[B[i]] = true;
      if (markB[A[i]]) counter++;
      markA[A[i]] = true;

      ans[i] = counter;
    }

    return ans;
  }
};