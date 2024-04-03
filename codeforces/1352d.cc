#include <bits/stdc++.h>
using namespace std;

const int kMax = 1e6 + 5;
int n, q, a[kMax], b[kMax];

bool check(int x) {
  int lcnt = 0, rcnt = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] > x)
      rcnt++;
    else
      lcnt++;
  }
  for (int i = 1; i <= q; i++) {
    if (b[i] > 0) {
      if (b[i] > x)
        rcnt++;
      else
        lcnt++;
    } else {
      if (lcnt >= -b[i])
        lcnt--;
      else
        rcnt--;
    }
  }
  return lcnt > 0;
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= q; i++) cin >> b[i];
  int left = 0, right = 1e7, mid, ans = 0;
  while (left <= right) {
    mid = (left + right) / 2;
    if (check(mid)) {
      ans = mid;
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  cout << ans << '\n';
  return 0;
}