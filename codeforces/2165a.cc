#include <bits/stdc++.h>
#ifdef LOCAL
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;

inline int patty(int n, list<int>& a) {
  auto get_prev_iter = [&](list<int>::iterator u) -> list<int>::iterator {
    if (u == a.begin()) return prev(a.end());
    return prev(u);
  };
  auto get_next_iter = [&](list<int>::iterator u) -> list<int>::iterator {
    if (next(u) == a.end()) return a.begin();
    return next(u);
  };
  auto is_hole = [&](list<int>::iterator u) -> bool {
    return *u <= min(*get_next_iter(u), *get_prev_iter(u));
  };
  debug(a);
  deque<list<int>::iterator> q;
  unordered_set<int*> erased;
  for (auto it = a.begin(); it != a.end(); it++) {
    if (is_hole(it)) q.push_back(it);
  }
  debug(q.size());
  for (auto x : q) {
    debug(*x);
  }
  int res = 0;
  while (a.size() > 1) {
    auto it = q.front();
    q.pop_front();
    if (erased.count(&(*it))) continue;
    auto left = get_prev_iter(it);
    auto right = get_next_iter(it);
    res += min(*left, *right);
    debug(res);
    erased.insert(&(*it));
    a.erase(it);
    if (is_hole(left)) q.push_back(left);
    if (is_hole(right)) q.push_back(right);
  }
  return res;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    list<int> a;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      a.push_back(x);
    }
    cout << patty(n, a) << "\n";
  }

  return 0;
}
