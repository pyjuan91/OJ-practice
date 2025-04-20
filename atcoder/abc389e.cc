#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
using namespace std;
using ui128 = __uint128_t;

ui128 input() {
  ui128 res = 0;
  string s;
  cin >> s;
  for (char c : s) {
    res = res * 10 + (c - '0');
  }
  return res;
}

void output(ui128 x) {
  if (x == 0) {
    cout << 0;
    return;
  }
  string s;
  while (x > 0) {
    s += (x % 10) + '0';
    x /= 10;
  }
  reverse(s.begin(), s.end());
  cout << s;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  ui128 n = input();
  ui128 m = input();
  vector<ui128> a(n);
  for (ui128 i = 0; i < n; ++i) {
    a[i] = input();
  }

  ui128 l = 0, r = m + 1;
  while (l + 1 < r) {
    ui128 mid = (l + r) / 2;
    ui128 sum = 0;
    for (ui128 i = 0; i < n; i++) {
      ui128 t = mid / a[i];
      ui128 ki = (t + 1) / 2;
      if (ki > 0) {
        sum += ki * ki * a[i];
        if (sum > m) break;
      }
    }
    if (sum > m) {
      r = mid;
    } else {
      l = mid;
    }
  }

  ui128 cost = 0;
  ui128 bought = 0;
  for (ui128 i = 0; i < n; i++) {
    ui128 t = l / a[i];
    ui128 ki = (t + 1) / 2;
    if (ki > 0) {
      cost += ki * ki * a[i];
      bought += ki;
      if (cost > m) break;
    }
  }

  bought += (m - cost) / (l + 1);
  output(bought);
  cout << '\n';
  return 0;
}
