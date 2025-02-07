#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int& x : a) cin >> x;

  unordered_set<int> s;
  vector<int> cur_comb;
  auto kazuha = [&](auto&& self, int i) -> void {
    if (i == n) {
      int x = 0;
      for (int y : cur_comb) x ^= y;
      debug(cur_comb, x);
      s.insert(x);
      return;
    }

    // merge to any existing subset
    size_t sz = cur_comb.size();
    for (size_t j = 0; j < sz; ++j) {
      cur_comb[j] += a[i];
      debug(cur_comb);
      self(self, i + 1);
      cur_comb[j] -= a[i];
    }

    // create a new subset
    cur_comb.push_back(a[i]);
    debug(cur_comb);
    self(self, i + 1);
    cur_comb.pop_back();
    };
  kazuha(kazuha, 0);
  cout << s.size() << '\n';

  return 0;
}
