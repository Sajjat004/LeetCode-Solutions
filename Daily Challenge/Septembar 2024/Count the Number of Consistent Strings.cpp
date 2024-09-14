// Challenge Date: 12 Sep, 2024
class Solution {
public:
  int countConsistentStrings(string allowed, vector<string>& words) {
    vector<bool> have(26, false);
    for (char ch : allowed) {
      have[ch - 'a'] = true;
    }

    int ans = 0;
    for (string word : words) {
      bool valid = true;

      for (char ch : word) {
        if (have[ch - 'a'] == false) valid = false;
      }

      if (valid) ans++;
    }

    return ans;
  }
};