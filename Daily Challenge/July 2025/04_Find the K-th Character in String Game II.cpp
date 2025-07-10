using ll = long long;
class Solution {
public:
  char kthCharacter(long long k, vector<int>& operations) {
    if (k == 1) return 'a';
    ll len = 1;
    int op = 0;
    for (int i = 0; i < 100; ++i) {
      len *= 2LL;
      if (len >= k) {
        op = operations[i];
        k = k - len / 2;
        break;
      }
    }
    char ans = kthCharacter(k, operations);
    if (op == 1) {
      ans = (ans == 'z') ? 'a' : ans + 1;
    }
    return ans;
  }
};