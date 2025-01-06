class Solution {
public:
  vector<int> minOperations(string boxes) {
    int n = boxes.size();
    boxes = "#" + boxes;

    vector<int> left(n + 1, 0), right(n + 1, 0);
    int count = 0;
    int operations = 0;
    for (int i = 1; i <= n; ++i) {
      operations += count;
      left[i] = operations;
      count += boxes[i] - '0';
    }

    count = 0;
    operations = 0;
    for (int i = n; i >= 1; --i) {
      operations += count;
      right[i] = operations;
      count += boxes[i] - '0';
    }

    vector<int> result(n);
    for (int i = 1; i <= n; ++i) {
      result[i - 1] = left[i] + right[i];
    }

    return result;
  }
};