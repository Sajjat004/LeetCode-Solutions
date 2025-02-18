class Solution {
  public:
    string smallestNumber(string pattern) {
      int n = pattern.size();
      stack<int> numStack;
      string result = "";

      for (int index = 0; index <= n; index++) {
        numStack.push(index + 1);

        if (index == n || pattern[index] == 'I') {
          while (!numStack.empty()) {
            result += to_string(numStack.top());
            numStack.pop();
          }
        }
      }

      return result;
    }
  };