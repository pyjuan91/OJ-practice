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
  int cnt[14] = { 0 }, x, y;
  for (int i = 0; i < 7; i++) {
    cin >> x;
    cnt[x]++;
  }
  x = y = -1;
  for (int i = 1; i <= 13; i++) if (cnt[i] >= 3) x = i;
  for (int i = 1; i <= 13; i++) if (cnt[i] >= 2 and i != x) y = i;
  if (x != -1 and y != -1) cout << "Yes";
  else cout << "No";
  return 0;
}
