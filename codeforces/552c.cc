#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;

bool chaewon(int n, int m) {
  if (n == 2) return true;
  vector<int> re_base;
  while (m) {
    re_base.push_back(m % n);
    m /= n;
  }
  // debug(re_base);
  vector<bool> used(101, false);
  for (int i = 0; i < re_base.size(); i++) {
    if (re_base[i] >= n) {
      if (i == re_base.size() - 1)
        re_base.push_back(1);
      else
        re_base[i + 1]++;
      re_base[i] -= n;
    }
    if (re_base[i] == 0) continue;
    if (re_base[i] == 1) {
      if (used[i]) return false;
      used[i] = true;
    } else if (re_base[i] == n - 1) {
      if (used[i]) return false;
      used[i] = true;
      if (i == re_base.size() - 1)
        re_base.push_back(1);
      else
        re_base[i + 1]++;
    } else {
      return false;
    }
  }
  return true;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  cout << (chaewon(n, m) ? "YES" : "NO") << '\n';
  return 0;
}
