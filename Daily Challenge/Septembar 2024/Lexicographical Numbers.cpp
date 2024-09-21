// Challenge Date: 21 Sep, 2024

class Solution {
public:
  vector<int> lexicalOrder(int n) {
    vector<int> answer;
    
    for (int i = 1; i <= n; ++i) {
      answer.push_back(i);
    }

    sort(answer.begin(), answer.end(), [](int a, int b) -> bool {
      return to_string(a) < to_string(b);
    });

    return answer;
  }
};