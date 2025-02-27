class Solution {
public:
  int lenLongestFibSubseq(vector<int>& arr) {
    int n = arr.size();
    unordered_set<int> numSet(arr.begin(), arr.end());
    int maxLength = 0;

    for (int start = 0; start < n; ++start) {
      for (int next = start + 1; next < n; ++next) {
        int prev = arr[next];
        int curr = arr[start] + arr[next];
        int len = 2;

        while (numSet.count(curr)) {
          int temp = curr;
          curr += prev;
          prev = temp;
          len++;
        }

        maxLength = max(maxLength, len);
      }
    }

    return maxLength >= 3 ? maxLength : 0;
  }
};