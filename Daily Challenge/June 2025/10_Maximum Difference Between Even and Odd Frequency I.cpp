class Solution {
public:
  int maxDifference(string s) {
    vector<int> frequencyOfAlphabet(26, 0);
    for (char c : s) {
      frequencyOfAlphabet[c - 'a']++;
    }

    int maxOddFrequency = 0;
    int minEvenFrequency = INT_MAX;

    for (int i = 0; i < 26; i++) {
      if (frequencyOfAlphabet[i] > 0) {
        if (frequencyOfAlphabet[i] % 2 == 0) {
          minEvenFrequency = min(minEvenFrequency, frequencyOfAlphabet[i]);
        } else {
          maxOddFrequency = max(maxOddFrequency, frequencyOfAlphabet[i]);
        }
      }
    }

    return maxOddFrequency - minEvenFrequency;
  }
};