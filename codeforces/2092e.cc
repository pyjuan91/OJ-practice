#include <bits/stdc++.h>
#include <atcoder/modint>
#ifndef ONLINE_JUDGE
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;
using mint = atcoder::modint1000000007;

mint fast_power(mint base, int exp) {
  mint result = 1;
  while (exp) {
    if (exp & 1) {
      result *= base;
    }
    base *= base;
    exp >>= 1;
  }
  return result;
}

bool is_corner(int x, int y, int n, int m) {
  return (x == 1 and y == 1) or (x == n and y == m) or (x == n and y == 1) or (x == 1 and y == m);
}

bool is_edge(int x, int y, int n, int m) {
  return (x == 1 or x == n or y == 1 or y == m) and not is_corner(x, y, n, m);
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n, m, k;
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    vector<tuple<int, int, int>> a(k);
    for (int i = 0; i < k; i++) {
      int x, y, c;
      cin >> x >> y >> c;
      a[i] = { x, y, c };
    }
    int green = n * m - k;
    int edge_cnt = 2 * (n + m - 4);
    int fix_edge_cnt = 0, predecided = 0;
    for (auto [x, y, c] : a) {
      if (is_edge(x, y, n, m)) {
        fix_edge_cnt++;
        predecided ^= c;
      }
    }
    int free_edge_cnt = edge_cnt - fix_edge_cnt;
    mint res;
    if (free_edge_cnt) {
      res = fast_power(2, green - 1);
    }
    else {
      if (predecided) res = 0;
      else res = fast_power(2, green);
    }
    cout << res.val() << '\n';
  }
  return 0;
}
