#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
using namespace std;

struct Interval {
  int l, r, id;
  bool operator<(const Interval& other) const {
    if (l == other.l) return r > other.r;
    return l < other.l;
  }
  Interval(int l, int r, int id) : l(l), r(r), id(id) {}
  Interval() {}
};

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<Interval> intervals(m);
  int whole_index = -1;
  for (int i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    if (l == 1 && r == n) {
      whole_index = i;
    }
    intervals[i] = Interval(l, r, i);
  }

  if (whole_index != -1) {
    cout << "1\n";
    for (int i = 0; i < m; i++) {
      if (i == whole_index) cout << "1 ";
      else cout << "0 ";
    }
    cout << "\n";
    return 0;
  }

  if (m == 1) {
    cout << "-1\n";
    return 0;
  }

  sort(intervals.begin(), intervals.end());

  int smallest_l_with_r_eq_n = -1;
  int largest_r_with_l_eq_1 = -1;
  for (int i = 0; i < m; i++) {
    if (intervals[i].r == n) {
      if (smallest_l_with_r_eq_n == -1 or intervals[i].l < intervals[smallest_l_with_r_eq_n].l) {
        smallest_l_with_r_eq_n = i;
      }
    }
    if (intervals[i].l == 1) {
      if (largest_r_with_l_eq_1 == -1 or intervals[i].r > intervals[largest_r_with_l_eq_1].r) {
        largest_r_with_l_eq_1 = i;
      }
    }
  }

  if (smallest_l_with_r_eq_n != -1 and largest_r_with_l_eq_1 != -1
    and intervals[smallest_l_with_r_eq_n].l <= intervals[largest_r_with_l_eq_1].r + 1) {
    cout << "2\n";
    for (int i = 0; i < m; i++) {
      if (i == intervals[smallest_l_with_r_eq_n].id or i == intervals[largest_r_with_l_eq_1].id) cout << "1 ";
      else cout << "0 ";
    }
    cout << "\n";
    return 0;
  }

  int smallest_r = -1, largest_l = -1;
  for (int i = 0; i < m; i++) {
    if (smallest_r == -1 or intervals[i].r < intervals[smallest_r].r) {
      smallest_r = i;
    }
    if (largest_l == -1 or intervals[i].l > intervals[largest_l].l) {
      largest_l = i;
    }
  }

  if (smallest_r != -1 and largest_l != -1
    and intervals[smallest_r].r < intervals[largest_l].l) {
    cout << "2\n";
    for (int i = 0; i < m; i++) {
      if (i == intervals[smallest_r].id or i == intervals[largest_l].id) cout << "2 ";
      else cout << "0 ";
    }
    cout << "\n";
    return 0;
  }

  int outsider = -1, insider = -1;
  set<pair<int, int>> s; // {r, id}
  for (int i = 0; i < m; i++) {
    auto it = s.lower_bound({ intervals[i].r, -1 });
    if (it != s.end()) {
      outsider = it->second;
      insider = intervals[i].id;
      break;
    }
    s.insert({ intervals[i].r, intervals[i].id });
  }

  if (outsider != -1 and insider != -1) {
    cout << "2\n";
    for (int i = 0; i < m; i++) {
      if (i == outsider) cout << "1 ";
      else if (i == insider) cout << "2 ";
      else cout << "0 ";
    }
    cout << "\n";
    return 0;
  }

  if (m == 2) {
    cout << "-1\n";
    return 0;
  }

  cout << "3\n";
  for (int i = 0; i < m; i++) {
    if (i == intervals[0].id or i == intervals[2].id) cout << "1 ";
    else if (i == intervals[1].id) cout << "2 ";
    else cout << "0 ";
  }
  cout << "\n";
  return 0;
}
