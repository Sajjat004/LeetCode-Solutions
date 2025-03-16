public class Solution {
  public long RepairCars(int[] ranks, int cars) {
    long left = 1, right = (long) 1e16;

    while (left <= right) {
      long mid = (left + right) / 2;

      if (CanRepair(ranks, cars, mid)) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }

    return left;
  }

  private bool CanRepair(int[] ranks, int cars, long time) {

    long carsRepaired = 0;

    for (int i = 0; i < ranks.Length; ++i) {
      long repairs = time / ranks[i];
      repairs = (long) Math.Sqrt(repairs);
      carsRepaired += repairs;
    }

    return carsRepaired >= cars;
  }
}