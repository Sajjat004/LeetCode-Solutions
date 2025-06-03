template<typename type> class SegTreeLazyMax {
private:
  struct Type {
    type mx, lazy;
    Type() : mx(0), lazy(0) {}
  };

  vector<Type> tree;
  vector<type> ar;
  int n;

  void build(int at, int b, int e) {
    if (b == e) {
      tree[at].mx = ar[b];
      return;
    }
    int mid = (b + e) >> 1;
    build(2 * at, b, mid);
    build(2 * at + 1, mid + 1, e);
    tree[at].mx = max(tree[2 * at].mx, tree[2 * at + 1].mx);
  }

  void propagate(int at, int b, int e) {
    tree[at].mx += tree[at].lazy;
    if (b != e) {
      tree[2 * at].lazy += tree[at].lazy;
      tree[2 * at + 1].lazy += tree[at].lazy;
    }
    tree[at].lazy = 0;
  }

  void update(int at, int b, int e, int l, int r, type val) {
    if (tree[at].lazy) propagate(at, b, e);
    if (r < b or e < l) return;
    if (l <= b and e <= r) {
      tree[at].mx += val;
      if (b != e) {
        tree[2 * at].lazy += val;
        tree[2 * at + 1].lazy += val;
      }
      return;
    }
    int mid = (b + e) >> 1;
    update(2 * at, b, mid, l, r, val);
    update(2 * at + 1, mid + 1, e, l, r, val);
    tree[at].mx = max(tree[2 * at].mx, tree[2 * at + 1].mx);
  }

  type query(int at, int b, int e, int l, int r) {
    if (tree[at].lazy) propagate(at, b, e);
    if (r < b or e < l) return INT_MIN;
    if (l <= b and e <= r) return tree[at].mx;
    int mid = (b + e) >> 1;
    type x = query(2 * at, b, mid, l, r);
    type y = query(2 * at + 1, mid + 1, e, l, r);
    return max(x, y);
  }

public:
  SegTreeLazyMax(int n, vector<type>& ar) : ar(ar) {
    this->n = n;
    tree.resize(4 * n);
    build(1, 0, n - 1);
  }
  void update(int l, int r, type val) {
    update(1, 0, n - 1, l, r, val);
  }
  type query(int l, int r) {
    return query(1, 0, n - 1, l, r);
  }
};

class Solution {
  bool isPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++) {
      if (x % i == 0) return false;
    }

    return true;
  }

public:
  vector<int> maximumCount(vector<int>& nums, vector<vector<int>>& queries) {
    int n = nums.size();
    unordered_map<int, set<int>> valueToIndex;
    for (int i = 0; i < n; i++) {
      if (isPrime(nums[i])) {
        valueToIndex[nums[i]].insert(i);
      }
    }

    vector<int> leftContribution(n, 0);
    vector<int> rightContribution(n, 0);
    vector<int> totalContribution(n - 1, 0);
    for (auto& [value, indices] : valueToIndex) {
      int indexL = *indices.begin();
      int indexR = *indices.rbegin();
      leftContribution[indexL]++;
      rightContribution[indexR]++;
    }
    for (int i = 1; i < n; i++) {
      leftContribution[i] += leftContribution[i - 1];
    }
    for (int i = n - 2; i >= 0; i--) {
      rightContribution[i] += rightContribution[i + 1];
    }
    for (int i = 0; i + 1 < n; ++i) {
      totalContribution[i] = leftContribution[i] + rightContribution[i + 1];
    }

    vector<int> maxCount;
    SegTreeLazyMax<int> segTree(n - 1, totalContribution);
    for (auto& query : queries) {
      int index = query[0];
      int value = query[1];

      if (isPrime(nums[index])) {
        if (index == *valueToIndex[nums[index]].begin()) {
          int a = *valueToIndex[nums[index]].begin();
          valueToIndex[nums[index]].erase(a);
          if (valueToIndex[nums[index]].empty()) {
            segTree.update(0, n - 2, -1);
          } else {
            int b = *valueToIndex[nums[index]].begin();
            segTree.update(a, b - 1, -1);
          }
        } else if (index == *valueToIndex[nums[index]].rbegin()) {
          int b = *valueToIndex[nums[index]].rbegin();
          valueToIndex[nums[index]].erase(b);
          if (valueToIndex[nums[index]].empty()) {
            segTree.update(0, n - 2, -1);
          } else {
            int a = *valueToIndex[nums[index]].rbegin();
            segTree.update(a, b - 1, -1);
          }
        } else {
          valueToIndex[nums[index]].erase(index);
        }
      }

      nums[index] = value;
      if (isPrime(value)) {
        if (valueToIndex[value].empty()) {
          valueToIndex[value].insert(index);
          segTree.update(0, n - 2, 1);
        } else {
          if (index < *valueToIndex[value].begin()) {
            int a = *valueToIndex[value].begin();
            valueToIndex[value].insert(index);
            segTree.update(index, a - 1, 1);
          } else if (index > *valueToIndex[value].rbegin()) {
            int b = *valueToIndex[value].rbegin();
            valueToIndex[value].insert(index);
            segTree.update(b, index - 1, 1);
          } else {
            valueToIndex[value].insert(index);
          }
        }
      }

      maxCount.push_back(segTree.query(0, n - 2));
    }

    return maxCount;
  }
};