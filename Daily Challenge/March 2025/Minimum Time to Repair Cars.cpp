class Solution {
public:
  long long repairCars(vector<int>& ranks, int cars) {
    long long left = 1, right = 1e16;

    while (left <= right) {
      long long mid = (left + right) / 2;

      if (canRepair(ranks, cars, mid)) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }

    return left;
  }

private:
  bool canRepair(vector<int>& ranks, int cars, long long time) {
    long long carCount = 0;

    for (int i = 0; i < ranks.size(); ++i) {
      long long repair = time / ranks[i];
      repair = sqrt(repair);
      carCount += repair;
    }

    return carCount >= cars;
  }
};