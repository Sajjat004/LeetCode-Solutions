#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int test; cin >> test;
  while (test--) {
    int n; cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }

    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    string posibility = "NO";

    for (int i = 1; i < n - 1; ++i) {
      for (int j = 1; j < n - 1; ++j) {
        if (a[0] + b[0] < a[i] + b[j] && a[n - 1] + b[n - 1] > a[i] + b[j]) {
          posibility = "YES";
          break;
        }
      }
    }

    cout << posibility << endl;
  }
  
  return 0;
}