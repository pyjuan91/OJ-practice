#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, x, su = 0;
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> x;
    su += x;
  }
  cout << -su;
  return 0;
}
