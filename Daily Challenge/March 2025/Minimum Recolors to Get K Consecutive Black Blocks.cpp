class Solution {
public:
  int minimumRecolors(string blocks, int k) {
    int n = blocks.size();
    vector<int> prefixSumOfWhite(n + 1, 0);
    for (int i = 0; i < n; i++) {
      prefixSumOfWhite[i + 1] = prefixSumOfWhite[i] + (blocks[i] == 'W');
    }

    int minOperations = INT_MAX;
    for (int i = 1; i + k - 1 <= n; i++) {
      int operations = prefixSumOfWhite[i + k - 1] - prefixSumOfWhite[i - 1];
      minOperations = min(minOperations, operations);
    }

    return minOperations;
  }
};