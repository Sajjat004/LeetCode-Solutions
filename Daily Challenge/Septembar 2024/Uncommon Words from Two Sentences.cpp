// Challenge Date: 17 Sep, 2024

class Solution {
public:
  vector<string> uncommonFromSentences(string s1, string s2) {
    stringstream ss1(s1);
    stringstream ss2(s2);
    string word;

    vector<string> words1;
    while (ss1 >> word) {
      words1.push_back(word);
    }

    vector<string> words2;
    while (ss2 >> word) {
      words2.push_back(word);
    }

    vector<string> answer;
    map<string, int> m;

    for (auto x : words1) m[x]++;
    for (auto x : words2) m[x]++;

    for (auto x : words1) {
      if (m[x] == 1) answer.push_back(x);
    }
    for (auto x : words2) {
      if (m[x] == 1) answer.push_back(x);
    }

    return answer;
  }
};