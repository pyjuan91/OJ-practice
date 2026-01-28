#include <bits/stdc++.h>
#ifdef LOCAL
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
  for (auto& x : a) cin >> x;
  if (a.front() == 0 and a.back() == 0) {
    cout << "NO\n";
    return 0;
  }
  int right_dist = 0;
  while (a[right_dist] != 0 and right_dist != n) right_dist++;
  if (right_dist == n) {
    if (n % 2)
      cout << "YES\n";
    else
      cout << "NO\n";
    return 0;
  }
  if (right_dist % 2) {
    cout << "YES\n";
    return 0;
  }
  int left_dist = 0;
  for (int i = n - 1; i >= 0 && a[i] != 0; i--, left_dist++);
  if (left_dist % 2) {
    cout << "YES\n";
    return 0;
  }
  cout << "NO\n";
  return 0;
}
