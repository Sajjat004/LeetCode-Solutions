class Solution {
public:
  vector<int> findEvenNumbers(vector<int>& digits) {
    vector<int> digitsFrequency(10, 0);
    for (int digit : digits) {
      digitsFrequency[digit]++;
    }

    auto isValid = [&](int firstDigit, int middleDigit, int lastDigit) {
      vector<int> frequency = digitsFrequency;
      frequency[firstDigit]--;
      frequency[middleDigit]--;
      frequency[lastDigit]--;

      return frequency[firstDigit] >= 0 && frequency[middleDigit] >= 0 && frequency[lastDigit] >= 0;
    };

    vector<int> result;

    for (int lastDigit = 0; lastDigit <= 9; lastDigit += 2) {
      for (int middleDigit = 0; middleDigit <= 9; middleDigit++) {
        for (int firstDigit = 1; firstDigit <= 9; firstDigit++) {
          if (isValid(firstDigit, middleDigit, lastDigit)) {
            int number = firstDigit * 100 + middleDigit * 10 + lastDigit;
            if (number >= 100) {
              result.push_back(number);
            }
          }
        }
      }
    }

    sort(result.begin(), result.end());
    return result;
  }
};