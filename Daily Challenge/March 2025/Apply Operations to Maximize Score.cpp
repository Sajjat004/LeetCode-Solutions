class Solution {
  public:
    const int MOD = 1e9 + 7;
  
    int maximumScore(vector<int>& nums, int k) {
      int n = nums.size();
      vector<int> primeScores(n);
  
      // Calculate the prime score for each number in nums
      for (int index = 0; index < n; ++index) {
        int num = nums[index];
  
        for (int factor = 2; factor * factor <= num; ++factor) {
          if (num % factor == 0) {
            primeScores[index]++;
  
            while (num % factor == 0) num /= factor;
          }
        }
  
        if (num >= 2) primeScores[index]++;
      }
  
      vector<int> nextDominant(n, n);
      vector<int> prevDominant(n, -1);
      stack<int> decreasingPrimeScoreStack;
  
      // Calculate the next and previous dominant indices for each number
      for (int index = 0; index < n; ++index) {
        while (!decreasingPrimeScoreStack.empty() &&
               primeScores[decreasingPrimeScoreStack.top()] <
                   primeScores[index]) {
          int topIndex = decreasingPrimeScoreStack.top();
          decreasingPrimeScoreStack.pop();
  
          nextDominant[topIndex] = index;
        }
  
        if (!decreasingPrimeScoreStack.empty())
          prevDominant[index] = decreasingPrimeScoreStack.top();
  
        decreasingPrimeScoreStack.push(index);
      }
  
      // Calculate the number of subarrays in which each element is dominant
      vector<long long> numOfSubarrays(n);
      for (int index = 0; index < n; ++index) {
        long long left = index - prevDominant[index];
        long long right = nextDominant[index] - index;
        numOfSubarrays[index] = left * right;
      }
  
      // Sort the array based on the values and their indices
      vector<pair<int, int>> sortedArray(n);
      for (int index = 0; index < n; ++index) {
        sortedArray[index] = {nums[index], index};
      }
      sort(sortedArray.begin(), sortedArray.end(), greater<>());
  
      long long score = 1;
      int processingIndex = 0;
  
      // Process the sorted array to calculate the maximum score
      while (k > 0) {
        auto [num, index] = sortedArray[processingIndex++];
  
        long long operations = min((long long)k, numOfSubarrays[index]);
        score = (score * power(num, operations)) % MOD;
        k -= operations;
      }
  
      return score;
    }
  
  private:
    // Helper function to calculate the power of a number modulo MOD
    long long power(long long base, long long exp) {
      long long result = 1;
      while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
      }
  
      return result;
    }
  };