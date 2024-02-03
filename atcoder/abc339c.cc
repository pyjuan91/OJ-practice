#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] += a[i - 1];
  }
  int mi = *min_element(a.begin() + 1, a.end());
  int res = mi < 0 ? a[n] - mi : a[n];
  cout << res << "\n";
  return 0;
}
