class Solution {
  public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
      vector<int> lessTahanPivot;
      vector<int> equalToPivot;
      vector<int> greaterThanPivot;

      for (int i = 0; i < nums.size(); i++) {
        if (nums[i] < pivot) {
          lessTahanPivot.push_back(nums[i]);
        } else if (nums[i] == pivot) {
          equalToPivot.push_back(nums[i]);
        } else {
          greaterThanPivot.push_back(nums[i]);
        }
      }

      vector<int> result;
      result.insert(result.end(), lessTahanPivot.begin(), lessTahanPivot.end());
      result.insert(result.end(), equalToPivot.begin(), equalToPivot.end());
      result.insert(result.end(), greaterThanPivot.begin(), greaterThanPivot.end());

      return result;
    }
  };