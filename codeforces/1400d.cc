#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> a(n + 1);
    vector<vector<int>> pref(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      pref[a[i]][i] = 1;
      for (int j = 1; j <= n; j++) {
        pref[j][i] += pref[j][i - 1];
      }
    }
    int res = 0;
    for (int j = 2; j <= n - 2; j++) {
      for (int k = j + 1; k <= n - 1; k++) {
        int cnt_ak = pref[a[k]][j - 1];
        int cnt_aj = pref[a[j]][n] - pref[a[j]][k];
        res += cnt_ak * cnt_aj;
      }
    }
    cout << res << '\n';
  }
  return 0;
}
