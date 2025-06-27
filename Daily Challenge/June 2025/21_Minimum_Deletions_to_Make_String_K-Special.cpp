class Solution {
public:
  int minimumDeletions(string word, int k) {
    vector<int> freq(26, 0);
    for (char ch : word) {
      freq[ch - 'a']++;
    }

    sort(freq.begin(), freq.end());
    vector<int> freqPre(26, 0);
    for (int i = 0; i < 26; ++i) {
      freqPre[i] = (i == 0 ? 0 : freqPre[i - 1]) + freq[i];
    }

    int minDeletions = INT_MAX;
    for (int i = 0; i < 26; ++i) {
      int deletions = 0;
      for (int j = 0; j < i; ++j) deletions += freq[j];
      for (int j = i + 1; j < 26; ++j) {
        if (freq[j] > freq[i] + k) {
          deletions += freq[j] - (freq[i] + k);
        }
      }
      minDeletions = min(minDeletions, deletions);
    }

    return minDeletions;
  }
};