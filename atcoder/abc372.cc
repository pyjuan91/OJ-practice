#include <bits/stdc++.h>
#include <atcoder/dsu>
#ifndef ONLINE_JUDGE
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n, q, op, u, v;
  cin >> n >> q;
  atcoder::dsu d(n);
  map<int, set<int>> mp;
  for (int i = 0; i < n; i++) mp[i].insert(i);
  while (q--) {
    cin >> op >> u >> v;
    if (op == 1) {
      if (d.same(u - 1, v - 1)) continue;
      int up = d.leader(u - 1), vp = d.leader(v - 1);
      if (mp[up].size() < mp[vp].size()) swap(up, vp);
      d.merge(u - 1, v - 1);
      for (int x : mp[vp]) mp[up].insert(x);
      mp.erase(vp);
      // while (mp[up].size() > 10) mp[up].erase(mp[up].begin());
    }
    else {
      int x = d.leader(u - 1);
      // debug(op, u, v, x, mp[x]);
      if (!mp.count(x) or mp[x].size() < v) cout << -1 << '\n';
      else {
        auto it = mp[x].rbegin();
        while (--v) it++;
        cout << *it + 1 << '\n';
      }
    }
  }
  return 0;
}
