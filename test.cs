class Solution {
public:
  vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
    int n = nums1.size();
    vector<pair<int, int>> order;
    for (int i = 0; i < n; ++i) {
      order.push_back({nums1[i], i});
    }

    sort(order.begin(), order.end());
    vector<long long> result(n);
    long long sum = 0;
    set<int> s;

    int index = 0;
    while (index < n) {
      int index1 = index;
      while (index1 < n and order[index1].first == order[index].first) {
        result[order[index1].second] = sum;
        ++index1;
      }

      cout << "Result: ";
      for (int x : result) {
        cout << x << " ";
      }
      cout << '\n';

      index1 = index;
      while (index1 < n and order[index1].first == order[index].first) {
        s.insert(nums2[order[index1].second]);
        sum += nums2[order[index1].second];
        ++index1;
      }
      index = index1;
      cout << "S size: " << s.size() << '\n';
      
      while (s.size() > k) {
        sum -= *s.begin();
        s.erase(s.begin());
      }
      cout << "Sum: " << sum << '\n';
    }

    return result;
  }
};