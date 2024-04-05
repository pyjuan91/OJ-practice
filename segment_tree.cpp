#include <bits/stdc++.h>
using namespace std;

template <typename T>
class SegmentTree {
 private:
  std::vector<T> tree, lazy;
  std::vector<bool> updated;
  int n;

  void build(int node, int start, int end, const std::vector<T>& arr) {
    if (start == end) {
      tree[node] = arr[start];
    } else {
      int mid = (start + end) / 2;
      build(2 * node, start, mid, arr);
      build(2 * node + 1, mid + 1, end, arr);
      tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
  }

  void updateRange(int node, int start, int end, int l, int r, T val) {
    if (updated[node]) {
      tree[node] = lazy[node] * (end - start + 1);
      if (start != end) {
        lazy[node * 2] = lazy[node];
        lazy[node * 2 + 1] = lazy[node];
        updated[node * 2] = updated[node];
        updated[node * 2 + 1] = updated[node];
      }
      updated[node] = false;
    }
    if (start > end or start > r or end < l) return;
    if (start >= l and end <= r) {
      tree[node] = val * (end - start + 1);
      if (start != end) {
        lazy[node * 2] = val;
        lazy[node * 2 + 1] = val;
        updated[node * 2] = true;
        updated[node * 2 + 1] = true;
      }
      return;
    }
    int mid = (start + end) / 2;
    updateRange(node * 2, start, mid, l, r, val);
    updateRange(node * 2 + 1, mid + 1, end, l, r, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
  }

  T queryRange(int node, int start, int end, int l, int r) {
    if (start > end or start > r or end < l) return 0;
    if (updated[node]) {
      tree[node] = lazy[node] * (end - start + 1);
      if (start != end) {
        lazy[node * 2] = lazy[node];
        lazy[node * 2 + 1] = lazy[node];
        updated[node * 2] = updated[node];
        updated[node * 2 + 1] = updated[node];
      }
      updated[node] = false;
    }
    if (start >= l and end <= r) return tree[node];
    int mid = (start + end) / 2;
    T p1 = queryRange(node * 2, start, mid, l, r);
    T p2 = queryRange(node * 2 + 1, mid + 1, end, l, r);
    return p1 + p2;
  }

 public:
  SegmentTree(const std::vector<T>& arr) {
    n = arr.size();
    tree.resize(4 * n);
    lazy.resize(4 * n);
    updated.resize(4 * n, false);
    build(1, 0, n - 1, arr);
  }

  void updateRange(int l, int r, T val) { updateRange(1, 0, n - 1, l, r, val); }

  T queryRange(int l, int r) { return queryRange(1, 0, n - 1, l, r); }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n, m;
  string s;
  cin >> n >> m >> s;

  vector<vector<int>> cnt(26, vector<int>(n));
  for (int i = 0; i < n; i++) {
    cnt[s[i] - 'a'][i] = 1;
  }

  vector<SegmentTree<int>> seg;
  for (int i = 0; i < 26; i++) {
    seg.push_back(SegmentTree<int>(cnt[i]));
  }

  while (m--) {
    int op[3];
    for (int i = 0; i < 3; i++) cin >> op[i];
    int cnt[26] = {};
    for (int i = 0; i < 26; i++) {
      cnt[i] = seg[i].queryRange(op[0] - 1, op[1] - 1);
      if (cnt[i]) seg[i].updateRange(op[0] - 1, op[1] - 1, 0);
    }

    int pos = op[0] - 1;
    if (op[2] == 1) {
      for (int i = 0; i < 26; i++) {
        if (cnt[i] == 0) continue;
        seg[i].updateRange(pos, pos + cnt[i] - 1, 1);
        pos += cnt[i];
      }
    } else {
      for (int i = 25; i >= 0; i--) {
        if (cnt[i] == 0) continue;
        seg[i].updateRange(pos, pos + cnt[i] - 1, 1);
        pos += cnt[i];
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 26; j++) {
      if (seg[j].queryRange(i, i) == 1) {
        cout << (char)('a' + j);
        break;
      }
    }
  }
  return 0;
}