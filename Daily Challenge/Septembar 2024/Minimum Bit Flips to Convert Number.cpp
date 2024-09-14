// Challenge Date: 11 Sep, 2024
class Solution {
public:
  int minBitFlips(int start, int goal) {
    bitset<30> a(start);
    bitset<30> b(goal);

    int bitFlips = 0;
    for (int i = 0; i < 30; ++i) {
      if (a[i] != b[i]) bitFlips++;
    }

    return bitFlips;
  }
};