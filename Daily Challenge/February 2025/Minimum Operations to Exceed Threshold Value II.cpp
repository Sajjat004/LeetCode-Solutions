class Solution {
public:
  int minOperations(vector<int>& nums, int k) {
    priority_queue<long long, vector<long long>, greater<long long>> pq;

    for (int x : nums) {
      pq.push(x);
    }

    int minOperations = 0;
    while (pq.size() > 1 and pq.top() < k) {
      long long a = pq.top();
      pq.pop();
      long long b = pq.top();
      pq.pop();

      long long c = min(a, b) * 2 + max(a, b);
      pq.push(c);
      minOperations++;
    }

    return minOperations;
  }
};