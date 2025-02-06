class Solution {
public:
  int tupleSameProduct(vector<int>& nums) {
    map<int, int> count;
    int n = nums.size();

    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        count[nums[i] * nums[j]]++;
      }
    }

    int tuples = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        int product = nums[i] * nums[j];
        
        if (count.find(product) != count.end()) {
          if (count[product] >= 2) {
            tuples += (4 * (count[product] - 1));
          }
        }
      }
    }

    return tuples;
  }
};