class Solution {
  const int MOD = 1e9 + 7;
public:
  int lengthAfterTransformations(string s, int t) {
    vector<long long> frequency(26, 0);
    for (char c : s) {
      frequency[c - 'a']++;
    }

    for (int i = 0; i < t; ++i) {
      int zfreq = frequency[25] % MOD;
      for (int j = 25; j > 0; --j) {
        frequency[j] = frequency[j - 1] % MOD;
      }

      frequency[0] = zfreq % MOD;
      frequency[1] += zfreq;
      frequency[1] %= MOD;
    }

    int ans = 0;
    for (int i = 0; i < 26; ++i) {
      ans = (ans + frequency[i]) % MOD;
    }

    return ans;
  }
};