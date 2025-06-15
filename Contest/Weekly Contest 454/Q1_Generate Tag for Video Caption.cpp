class Solution {
  char changeSmall(char c) {
    if (c >= 'a' && c <= 'z') return c;
    if (c >= 'A' && c <= 'Z') {
      return c + ('a' - 'A');
    }
    return c;
  }

  char changeCapital(char c) {
    if (c >= 'A' && c <= 'Z') return c;
    if (c >= 'a' && c <= 'z') {
      return c - ('a' - 'A');
    }
    return c;
  }

public:
  string generateTag(string caption) {
    int n = caption.size();
    string result = "#";
    int limit = 99;
    bool getSpace = true;
    for (int i = 0; i < n and limit; ++i) {
      if (caption[i] != ' ') {
        if (getSpace) {
          result += changeCapital(caption[i]);
          getSpace = false;
        } else {
          result += changeSmall(caption[i]);
        }
        limit--;
      } else {
        getSpace = true;
      }
    }

    if (result.size() > 1) {
      result[1] = changeSmall(result[1]);
    }

    return result;
  }
};