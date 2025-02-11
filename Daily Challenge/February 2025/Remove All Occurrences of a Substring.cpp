class Solution {
public:
  string removeOccurrences(string s, string part) {
    int sLength = s.size();
    int partLength = part.size();
    stack<char> charStack;

    for (char x : s) {
      charStack.push(x);

      if (charStack.size() >= partLength and stackContainsPart(charStack, part)) {
        for (int i = 0; i < partLength; ++i) {
          charStack.pop();
        }
      }
    }

    string result = "";
    while (!charStack.empty()) {
      result = charStack.top() + result;
      charStack.pop();
    }

    return result;
  }

private:
  bool stackContainsPart(stack<char> charStack, string& part) {
    int partLength = part.size();

    for (int i = partLength - 1; i >= 0; --i) {
      if (charStack.top() != part[i]) return false;
      charStack.pop();
    }

    return true;
  }
};