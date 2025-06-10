class Solution {
public:
  int minDeletion(string s, int k) {
    vector<int> freq(26, 0);
    for (char c : s) {
      freq[c - 'a']++;
    }

    vector<int> freqCount;
    for (int i = 0; i < 26; ++i) {
      if (freq[i] > 0) {
        freqCount.push_back(freq[i]);
      }
    }

    sort(freqCount.begin(), freqCount.end());
    int ans = 0;
    for (int i = 0; (i + k) < freqCount.size(); ++i) {
      ans += freqCount[i];
    }

    return ans;
  }
};