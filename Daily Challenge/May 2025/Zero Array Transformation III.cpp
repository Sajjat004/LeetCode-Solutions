class Solution {
public:
  int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
    int n = nums.size();
    sort(queries.begin(), queries.end(), [](const vector<int>& a, const vector<int>& b) {
      return a[0] < b[0];
    });

    priority_queue<int> maxHeap;
    vector<int> deltaArray(n + 1, 0);
    int operations = 0;

    for (int i = 0, j = 0; i < n; ++i) {
      operations += deltaArray[i];

      while (j < queries.size() and queries[j][0] == i) {
        maxHeap.push(queries[j++][1]);
      }

      while (operations < nums[i] and !maxHeap.empty() and maxHeap.top() >= i) {
        operations++;
        deltaArray[maxHeap.top() + 1]--;
        maxHeap.pop();
      }

      if (operations < nums[i]) {
        return -1;
      }
    }

    return maxHeap.size();
  }
};