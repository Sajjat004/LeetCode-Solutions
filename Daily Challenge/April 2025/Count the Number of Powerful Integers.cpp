class Solution {
public:
  long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
    return calculate(finish, s, limit) - calculate(start - 1, s, limit);
  }

private:
  long long calculate(long long _x, string s, int limit) {
    string x = to_string(_x);
    if (x.length() < s.length()) return 0;
    if (x.length() == s.length()) return x >= s ? 1 : 0;

    string suffix = x.substr(x.length() - s.length(), s.length());
    long long count = 0;
    int preLen = x.length() - s.length();

    for (int i = 0; i < preLen; i++) {
      if (limit < (x[i] - '0')) {
        count += (long)pow(limit + 1, preLen - i);
        return count;
      }
      count += (long)(x[i] - '0') * (long)pow(limit + 1, preLen - 1 - i);
    }
    if (suffix >= s) {
      count++;
    }

    return count;
  }
};