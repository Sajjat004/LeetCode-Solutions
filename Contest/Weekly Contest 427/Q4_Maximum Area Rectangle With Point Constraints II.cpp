template<typename type> class SegTreeMax {
  vector<type> tree;
  int n;

  void build(int at, int b, int e, vector<type>& arr) {
    if (b == e) {
      tree[at] = arr[b];
      return;
    }
    int mid = (b + e) >> 1;
    build(2 * at, b, mid, arr);
    build(2 * at + 1, mid + 1, e, arr);
    tree[at] = max(tree[2 * at], tree[2 * at + 1]);
  }

  void update(int at, int b, int e, int idx, type val) {
    if (e < idx or idx < b) return;
    if (b == e) {
      tree[at] = val;
      return;
    }
    int mid = (b + e) >> 1;
    update(2 * at, b, mid, idx, val);
    update(2 * at + 1, mid + 1, e, idx, val);
    tree[at] = max(tree[2 * at], tree[2 * at + 1]);
  }

  type query(int at, int b, int e, int l, int r) {
    if (r < b or e < l) return (type) INT_MIN;
    if (l <= b and e <= r) return tree[at];
    int mid = (b + e) >> 1;
    type x = query(2 * at, b, mid, l, r);
    type y = query(2 * at + 1, mid + 1, e, l, r);
    return max(x, y);
  }

public:
  SegTreeMax(int n, vector<type>& arr) {
    this->n = n;
    tree.assign(4 * n, 0);
    build(1, 1, n, arr);
  }

  void update(int idx, type val) {
    update(1, 1, n, idx, val);
  }

  type query(int l, int r) {
    if (l > r) return (type) -1;
    return query(1, 1, n, l, r);
  }
};

class Solution {
public:
  long long maxRectangleArea(vector<int>& xCoord, vector<int>& yCoord) {
    int n = xCoord.size();
    map<int, vector<int>> allXForY;
    set<int> uniqueX;
    for (int i = 0; i < n; ++i) {
      allXForY[yCoord[i]].push_back(xCoord[i]);
      uniqueX.insert(xCoord[i]);
    }

    map<int, int> xToIndex;
    int id = 0;
    for (int x : uniqueX) {
      xToIndex[x] = ++id;
    }
    vector<int> arr(id + 5, -1);
    SegTreeMax<int> segTree(id, arr);
    long long maxArea = -1;

    for (auto& [y, xList] : allXForY) {
      sort(xList.begin(), xList.end());
      if (xList.size() > 1) {
        for (int i = 0; i + 1 < xList.size(); ++i) {
          int x1 = xList[i];
          int x2 = xList[i + 1];
          int bestY1 = segTree.query(xToIndex[x1], xToIndex[x1]);
          int bestY2 = segTree.query(xToIndex[x2], xToIndex[x2]);
          int maxY = segTree.query(xToIndex[x1] + 1, xToIndex[x2] - 1);

          if (bestY1 == bestY2 and bestY1 != -1 and maxY < bestY1) {
            long long width = x2 - x1;
            long long height = y - bestY1;
            maxArea = max(maxArea, width * height);
          }
        }
      }
      
      for (int x : xList) {
        segTree.update(xToIndex[x], y);
      }
    }

    return maxArea;
  }
};