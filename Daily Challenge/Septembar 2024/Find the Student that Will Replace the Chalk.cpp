// Challenge Date: 02 Sep, 2024
class Solution {
    typedef long long ll;
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        vector<ll> pSum(n, 0LL);
        for (int i = 0; i < n; ++i) {
            if (i == 0) pSum[i] = chalk[i];
            else {
                pSum[i] = chalk[i] + pSum[i - 1];
            }
        }
        ll x = (ll) k;
        x %= pSum[n - 1];
        int l = 0, r = n - 1;
        int idx = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (pSum[mid] > x) {
                idx = mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        return idx;
    }
};