#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<vector<int>> a(n + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) cin >> a[i][j];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[i][j]) cout << j << ' ';
    }
    cout << '\n';
  }
  return 0;
}
