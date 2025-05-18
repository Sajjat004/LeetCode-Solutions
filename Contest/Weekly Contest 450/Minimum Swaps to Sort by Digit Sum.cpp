class Solution {
  int sumOfDigits(int n) {
    int sum = 0;
    while (n > 0) {
      sum += n % 10;
      n /= 10;
    }
    return sum;
  }

public:
  int minSwaps(vector<int>& nums) {
    map<int, int> Index;
    for (int i = 0; i < nums.size(); i++) {
      Index[nums[i]] = i;
    }

    sort(nums.begin(), nums.end(), [&](int a, int b) {
      if (sumOfDigits(a) == sumOfDigits(b)) {
        return a < b;
      }
      return sumOfDigits(a) < sumOfDigits(b);
    });

    vector<bool> visited(nums.size(), false);
    int swaps = 0;
    for (int i = 0; i < nums.size(); i++) {
      if (visited[i] || Index[nums[i]] == i) {
        continue;
      }

      int cycle_size = 0;
      int j = i;
      while (!visited[j]) {
        visited[j] = true;
        j = Index[nums[j]];
        cycle_size++;
      }

      if (cycle_size > 0) {
        swaps += (cycle_size - 1);
      }
    }

    return swaps;
  }
};