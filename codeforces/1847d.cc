#include <bits/stdc++.h>
using namespace std;

const int kMax = 2e5 + 5;
int n, m, q, s[kMax] = {};
int rk = 0, parent[kMax] = {}, pos[kMax] = {};
int l, r, x;
int total_ones = 0;

string str;

int find(int x) {
  if (x == parent[x]) return x;
  return parent[x] = find(parent[x]);
}

class SegmentTree {
 private:
  std::vector<int> tree;
  int n;

  void build(const std::vector<int>& arr, int v, int tl, int tr) {
    if (tl == tr) {
      tree[v] = arr[tl];
    } else {
      int tm = (tl + tr) / 2;
      build(arr, v * 2, tl, tm);
      build(arr, v * 2 + 1, tm + 1, tr);
      tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
  }

  int sum(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (l == tl && r == tr) {
      return tree[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v * 2, tl, tm, l, std::min(r, tm)) +
           sum(v * 2 + 1, tm + 1, tr, std::max(l, tm + 1), r);
  }

  void update(int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr) {
      tree[v] = new_val;
    } else {
      int tm = (tl + tr) / 2;
      if (pos <= tm)
        update(v * 2, tl, tm, pos, new_val);
      else
        update(v * 2 + 1, tm + 1, tr, pos, new_val);
      tree[v] = tree[v * 2] + tree[v * 2 + 1];
    }
  }

 public:
  SegmentTree(const std::vector<int>& arr) {
    n = arr.size();
    tree.resize(n * 4);
    build(arr, 1, 0, n - 1);
  }

  int rangeQuery(int l, int r) { return sum(1, 0, n - 1, l, r); }

  void pointUpdate(int pos, int new_val) { update(1, 0, n - 1, pos, new_val); }
};

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  iota(parent, parent + kMax, 0);

  cin >> n >> m >> q >> str;
  for (int i = 1; i <= n; i++) s[i] = str[i - 1] == '1';

  for (int i = 1; i <= m; i++) {
    cin >> l >> r;
    for (int j = l; j <= r; j = find(j + 1)) {
      if (pos[j] == 0) {
        pos[j] = ++rk;
        parent[j] = j + 1;
      }
    }
  }

  vector<int> arr(rk + 1, 0);
  for (int i = 1; i <= n; i++) {
    arr[pos[i]] += s[i];
    total_ones += s[i];
  }
  SegmentTree seg(arr);

  while (q--) {
    cin >> x;
    if (s[x]) {
      total_ones--;
      s[x] = 0;
      if (pos[x]) seg.pointUpdate(pos[x], 0);
    } else {
      total_ones++;
      s[x] = 1;
      if (pos[x]) seg.pointUpdate(pos[x], 1);
    }
    int full_ones = min(total_ones, rk);
    int current_ones = seg.rangeQuery(1, full_ones);
    cout << full_ones - current_ones << '\n';
  }
  return 0;
}
