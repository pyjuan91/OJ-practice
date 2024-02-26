#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n, m, l, r;
  cin >> t;
  while(t--) {
    cin >> n >> m;
    vector<int> a(n+1), ones_cnt(n+1, 0), diff_cnt(n+1, 0);
    for(int i = 1; i <= n; i++) {
      cin >> a[i];
      ones_cnt[i] = ones_cnt[i-1];
      diff_cnt[i] = diff_cnt[i-1];
      if(a[i] == 1) ones_cnt[i] += 1;
      else diff_cnt[i] += a[i] - 1;
    }
    while(m--) {
      cin >> l >> r;
      if (l == r) {
        cout << "NO\n";
        continue;
      }
      int ones = ones_cnt[r] - ones_cnt[l-1];
      int quota = diff_cnt[r] - diff_cnt[l-1];
      cout << (ones <= quota ? "YES\n" : "NO\n");
    }
  }
  return 0;
}
