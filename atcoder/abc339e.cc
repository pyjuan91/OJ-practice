#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMax = 5e5 + 5;

class SegmentTree {
 private:
  std::vector<int> tree;
  int n;

  int queryTree(int treeIndex, int lo, int hi, int i, int j) {
    if (lo > j || hi < i) {
      return INT_MIN;
    }

    if (i <= lo && j >= hi) {
      return tree[treeIndex];
    }

    int mid = lo + (hi - lo) / 2;

    if (i > mid) {
      return queryTree(2 * treeIndex + 2, mid + 1, hi, i, j);
    } else if (j <= mid) {
      return queryTree(2 * treeIndex + 1, lo, mid, i, j);
    }

    int leftQuery = queryTree(2 * treeIndex + 1, lo, mid, i, mid);
    int rightQuery = queryTree(2 * treeIndex + 2, mid + 1, hi, mid + 1, j);

    return std::max(leftQuery, rightQuery);
  }
  void updatePoint(int treeIndex, int lo, int hi, int arrIndex, int val) {
    if (lo == hi) {
      tree[treeIndex] = val;
      return;
    }

    int mid = lo + (hi - lo) / 2;

    if (arrIndex > mid) {
      updatePoint(2 * treeIndex + 2, mid + 1, hi, arrIndex, val);
    } else {
      updatePoint(2 * treeIndex + 1, lo, mid, arrIndex, val);
    }

    tree[treeIndex] =
        std::max(tree[2 * treeIndex + 1], tree[2 * treeIndex + 2]);
  }

 public:
  SegmentTree() {
    n = kMax;
    tree.assign(4 * n, 0);
  }
  void update(int index, int val) { updatePoint(0, 0, n - 1, index, val); }
  int queryMax(int i, int j) { return queryTree(0, 0, n - 1, i, j); }
};

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n, d, x, y, z;
  auto seg = SegmentTree();
  cin >> n >> d;
  while (n--) {
    cin >> x;
    y = seg.queryMax(max(0LL, x - d), min(x + d, kMax - 1));
    z = (y == INT_MIN ? 0 : y) + 1;
    seg.update(x, z);
  }
  cout << seg.queryMax(0, kMax - 1) << "\n";
  return 0;
}
