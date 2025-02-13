public class Solution {
  public int MinOperations(int[] nums, int k) {
    PriorityQueue<long, long> pq = new PriorityQueue<long, long>();

    foreach (int x in nums) {
      pq.Enqueue(x, x);
    }

    int operations = 0;

    while (pq.Count > 1 && pq.Peek() < k) {
      long x = pq.Dequeue();
      long y = pq.Dequeue();
      long sum = Math.Min(x, y) * 2 + Math.Max(x, y);
      pq.Enqueue(sum, sum);
      operations++;
    }

    return operations;
  }
}