#include <bits/stdc++.h>
#ifdef LOCAL
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;

int patty(int n, int d, vector<int>& a) {
  map<int, int> pos;
  int res = 0;
  for (int l = -1, r = 0; r < n; r++) {
    auto iter = pos.upper_bound(a[r] - d);
    while (iter != pos.end() && iter->first < a[r] + d) {
      l = max(l, iter->second);
      iter = pos.erase(iter);
    }
    res += r - l;
    pos[a[r]] = r;
    // debug(pos);
  }
  return res;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, d;
  cin >> n >> d;
  vector<int> a(n);
  for (auto& x : a) cin >> x;
  cout << patty(n, d, a) << "\n";
  return 0;
}
