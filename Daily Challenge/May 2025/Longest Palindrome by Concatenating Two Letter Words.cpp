class Solution {
public:
  int longestPalindrome(vector<string>& words) {
    unordered_map<string, int> count;

    int palindromeSize = 0;
    for (const string& word : words) {
      string revWord = string(word.rbegin(), word.rend());
      if (count[revWord] > 0) {
        palindromeSize += 4;
        count[revWord]--;
      } else {
        count[word]++;
      }
    }

    for (const auto& [word, cnt] : count) {
      if (word[0] == word[1] && cnt > 0) {
        palindromeSize += 2;
        break;
      }
    }

    return palindromeSize;
  }
};