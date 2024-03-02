#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMax = 2e5 + 5;
int n, q, op, x, y, a[kMax];
// first item in pair is the largest element in the segment
// second item in pair is the second largest element in the segment
pair<pair<int, int>, pair<int, int>> seg[4 * kMax];

void build(int v, int l, int r) {
  if (l == r) {
    seg[v] = {{a[l], 1}, {0, 0}};
  } else {
    int m = (l + r) / 2;
    build(2 * v, l, m);
    build(2 * v + 1, m + 1, r);
    map<int, int> mp;
    mp[seg[2 * v].first.first] += seg[2 * v].first.second;
    mp[seg[2 * v].second.first] += seg[2 * v].second.second;
    mp[seg[2 * v + 1].first.first] += seg[2 * v + 1].first.second;
    mp[seg[2 * v + 1].second.first] += seg[2 * v + 1].second.second;
    auto cur_largets = mp.rbegin();
    auto cur_second_largest = ++mp.rbegin();
    seg[v] = {{cur_largets->first, cur_largets->second},
              {cur_second_largest->first, cur_second_largest->second}};
  }
}

void update(int v, int l, int r, int pos, int val) {
  if (l == r) {
    seg[v] = {{val, 1}, {0, 0}};
  } else {
    int m = (l + r) / 2;
    if (pos <= m) {
      update(2 * v, l, m, pos, val);
    } else {
      update(2 * v + 1, m + 1, r, pos, val);
    }
    map<int, int> mp;
    mp[seg[2 * v].first.first] += seg[2 * v].first.second;
    mp[seg[2 * v].second.first] += seg[2 * v].second.second;
    mp[seg[2 * v + 1].first.first] += seg[2 * v + 1].first.second;
    mp[seg[2 * v + 1].second.first] += seg[2 * v + 1].second.second;
    auto cur_largets = mp.rbegin();
    auto cur_second_largest = ++mp.rbegin();
    seg[v] = {{cur_largets->first, cur_largets->second},
              {cur_second_largest->first, cur_second_largest->second}};
  }
}

pair<pair<int, int>, pair<int, int>> query(int v, int l, int r, int ql,
                                           int qr) {
  if (ql <= l && r <= qr) {
    return seg[v];
  }
  if (qr < l || r < ql) {
    return {{0, 0}, {0, 0}};
  }
  int m = (l + r) / 2;
  auto left = query(2 * v, l, m, ql, qr);
  auto right = query(2 * v + 1, m + 1, r, ql, qr);
  map<int, int> mp;
  mp[left.first.first] += left.first.second;
  mp[left.second.first] += left.second.second;
  mp[right.first.first] += right.first.second;
  mp[right.second.first] += right.second.second;
  auto cur_largets = mp.rbegin();
  auto cur_second_largest = ++mp.rbegin();
  return {{cur_largets->first, cur_largets->second},
          {cur_second_largest->first, cur_second_largest->second}};
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> a[i];
  build(1, 1, n);
  while (q--) {
    cin >> op >> x >> y;
    if (op == 1) {
      update(1, 1, n, x, y);
    } else {
      auto res = query(1, 1, n, x, y);
      cout << res.second.second << '\n';
    }
  }
  return 0;
}
