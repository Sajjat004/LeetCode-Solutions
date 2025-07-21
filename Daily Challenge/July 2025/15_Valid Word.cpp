class Solution {
  bool isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
           c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
  }
  bool isAlpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
  }
  bool isDigit(char c) {
    return c >= '0' && c <= '9';
  }
public:
  bool isValid(string word) {
    bool hasVowel = false;
    bool hasConsonant = false;
    bool hasSpecialChar = false;
    for (char c : word) {
      if (isAlpha(c)) {
        if (isVowel(c)) {
          hasVowel = true;
        } else {
          hasConsonant = true;
        }
      } else if (isDigit(c)) {
      } else {
        hasSpecialChar = true;
      }
    }
    return hasVowel && hasConsonant && !hasSpecialChar && word.size() >= 3;
  }
};