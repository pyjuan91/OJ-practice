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
using mint = atcoder::modint998244353;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto& x : a) cin >> x, x--;
  string s;
  cin >> s;
  mint res_left = 1, res_right = 1;
  vector<bool> picked(n, false);
  for (int i = 0; i < n; i++) {
    if (picked[a[i]]) {
      res_left = 0;
      break;
    }

    if (picked[(a[i] + 1) % n] and s[a[i]] == '?') res_left *= 2;

    if (not picked[(a[i] + 1) % n] and s[a[i]] == 'R') {
      res_left = 0;
      break;
    }

    picked[a[i]] = true;
  }

  picked.assign(n, false);
  for (int i = 0; i < n; i++) {
    if (picked[(a[i] + 1) % n]) {
      res_right = 0;
      break;
    }

    if (picked[a[i]] and s[a[i]] == '?') res_right *= 2;

    if (not picked[a[i]] and s[a[i]] == 'L') {
      res_right = 0;
      break;
    }

    picked[(a[i] + 1) % n] = true;
  }
  debug(res_left.val(), res_right.val());
  cout << (res_left + res_right).val() << '\n';
  return 0;
}
