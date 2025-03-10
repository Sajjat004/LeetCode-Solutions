class Solution {
  int lowerBound(int left, int right, int k, const vector<vector<int>>& prefixSum) {
    int l = left;
    int ans = -1;
    
    while (left <= right) {
      int mid = (left + right) >> 1;
      int A = prefixSum[mid]['a' - 'a'] - prefixSum[l - 1]['a' - 'a'];
      int E = prefixSum[mid]['e' - 'a'] - prefixSum[l - 1]['e' - 'a'];
      int I = prefixSum[mid]['i' - 'a'] - prefixSum[l - 1]['i' - 'a'];
      int O = prefixSum[mid]['o' - 'a'] - prefixSum[l - 1]['o' - 'a'];
      int U = prefixSum[mid]['u' - 'a'] - prefixSum[l - 1]['u' - 'a'];

      int consonant = mid - l + 1;
      consonant -= (A + E + I + O + U);

      if (A and E and I and O and U) {
        if (consonant == k) {
          ans = mid;
          right = mid - 1;
        } else if (consonant < k) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      } else {
        left = mid + 1;
      }
    }

    return ans;
  }

  int upperBound(int left, int right, int k, const vector<vector<int>>& prefixSum) {
    int l = left;
    int ans = -1;
    
    while (left <= right) {
      int mid = (left + right) >> 1;

      int A = prefixSum[mid]['a' - 'a'] - prefixSum[l - 1]['a' - 'a'];
      int E = prefixSum[mid]['e' - 'a'] - prefixSum[l - 1]['e' - 'a'];
      int I = prefixSum[mid]['i' - 'a'] - prefixSum[l - 1]['i' - 'a'];
      int O = prefixSum[mid]['o' - 'a'] - prefixSum[l - 1]['o' - 'a'];
      int U = prefixSum[mid]['u' - 'a'] - prefixSum[l - 1]['u' - 'a'];

      int consonant = mid - l + 1;
      consonant -= (A + E + I + O + U);
      
      if (A and E and I and O and U) {
        if (consonant == k) {
          ans = mid;
          left = mid + 1;
        } else if (consonant < k) {
          left = mid + 1;
        } else {
          right = mid - 1;
        }
      } else {
        left = mid + 1;
      }
    }

    return ans;
  }

public:
  long long countOfSubstrings(string word, int k) {
    int n = word.size();
    word = '?' + word;

    vector<vector<int>> prefixSum(n + 2, vector<int>(26, 0));

    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < 26; ++j) {
        prefixSum[i][j] = prefixSum[i - 1][j];
      }
      prefixSum[i][word[i] - 'a']++;
    }

    long long ans = 0;

    for (int i = 1; i <= n; ++i) {
      int left = lowerBound(i, n, k, prefixSum);
      if (left != -1) {
        int right = upperBound(i, n, k, prefixSum);
        ans += (right - left + 1);
      }
    }

    return ans;
  }
};