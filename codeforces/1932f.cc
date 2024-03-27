#include <bits/stdc++.h>
#define int long long
using namespace std;

const int kMax = 1e6 + 5;
int t, n, m, pre[kMax], most_left[kMax];
pair<int, int> a[kMax];
int best[kMax];

int chaewon() {
  sort(a + 1, a + m + 1, [](const pair<int, int> &x, const pair<int, int> &y) {
    return x.second < y.second;
  });
  for (int i = m; i >= 1; i--) {
    most_left[a[i].second] = min(most_left[a[i].second], a[i].first);
  }
  for (int i = n; i >= 1; i--) {
    most_left[i] = min(most_left[i], most_left[i + 1]);
  }
  for (int i = 1; i <= m; i++) pre[a[i].first]++, pre[a[i].second + 1]--;
  for (int i = 1; i <= n; i++) pre[i] += pre[i - 1];
  for (int i = 1; i <= n; i++) {
    best[i] = best[i - 1];
    if (pre[i]) {
      int pre_best = best[most_left[i] - 1];
      best[i] = max(best[i], pre_best + pre[i]);
    }
  }
  return best[n];
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 1; i <= n + 4; i++) pre[i] = 0, most_left[i] = i;
    for (int i = 1; i <= m; i++) cin >> a[i].first >> a[i].second;
    cout << chaewon() << '\n';
  }
  return 0;
}
