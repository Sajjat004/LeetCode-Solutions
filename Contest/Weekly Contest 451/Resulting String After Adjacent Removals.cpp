class Solution {
  char leftAdjacentChar(char c) {
    if (c == 'a') return 'z';
    return c - 1;
  }
  char rightAdjacentChar(char c) {
    if (c == 'z') return 'a';
    return c + 1;
  }
public:
  string resultingString(string s) {
    stack<char> st;

    for (char c : s) {
      if (!st.empty() and (st.top() == leftAdjacentChar(c) or st.top() == rightAdjacentChar(c))) {
        st.pop();
      } else {
        st.push(c);
      }
    }

    string result = "";
    while (!st.empty()) {
      result += st.top();
      st.pop();
    }
    reverse(result.begin(), result.end());

    return result;
  }
};