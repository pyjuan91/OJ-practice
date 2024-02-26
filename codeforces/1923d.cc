#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> a(n + 1), prefix(n + 1), nxt(n + 2);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      prefix[i] = prefix[i - 1] + a[i];
    }
    for (int i = n; i >= 1; i--) {
      if (i == n)
        nxt[i] = i;
      else if (a[i] == a[i + 1])
        nxt[i] = nxt[i + 1];
      else
        nxt[i] = i;
    }

    auto chaewon = [&](int id, int guess) {
      // test left_side
      int lid = max(id - guess, 1ll);
      if (a[id - 1] > a[id] || nxt[lid] != nxt[id - 1]) {
        int left_sum = prefix[id - 1] - prefix[lid - 1];
        if (left_sum > a[id]) return true;
      }
      // test right_side
      int rid = min(id + guess, n);
      if (a[id + 1] > a[id] || nxt[rid] != nxt[id + 1]) {
        int right_sum = prefix[rid] - prefix[id];
        if (right_sum > a[id]) return true;
      }
      return false;
    };

    for (int i = 1; i <= n; i++) {
      int l = 1, r = n, ans = -1;
      while (l <= r) {
        int mid = (l + r) / 2;
        // cout << "i: " << i << " mid: " << mid << '\n';
        if (chaewon(i, mid))
          ans = mid, r = mid - 1;
        else
          l = mid + 1;
      }
      cout << ans << " ";
    }
    cout << '\n';
  }
  return 0;
}
