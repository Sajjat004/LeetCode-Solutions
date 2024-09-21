// Challenge Date: 18 Sep, 2024

class Solution {

public:
  string largestNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end(), [] (int a, int b) -> bool {
      string sa = to_string(a);
      string sb = to_string(b);

      return (sa + sb) > (sb + sa);
    });

    if (nums[0] == 0) return "0";

    string answer = "";
    for (int n : nums) {
      answer += to_string(n);
    }

    return answer;
  }
};