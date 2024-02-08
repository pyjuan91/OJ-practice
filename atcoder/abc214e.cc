#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<pair<int, int>> a(n);
    for (auto &x : a) cin >> x.first >> x.second;
    sort(a.begin(), a.end());

    int cur_pos = a[0].first, idx = 0;
    multiset<int> pending_right;
    set<int> used;
    bool ok = true;
    while (cur_pos < INT32_MAX && ok) {
      while (idx < n && a[idx].first <= cur_pos) {
        pending_right.insert(a[idx].second);
        idx++;
      }
      if (!pending_right.empty()) {
        if (cur_pos <= *pending_right.begin()) {
          cur_pos++;
          pending_right.erase(pending_right.begin());
        } else {
          ok = false;
          break;
        }
      } else {
        if (idx < n)
          cur_pos = a[idx].first;
        else
          break;
      }
    }
    cout << (ok ? "Yes" : "No") << '\n';
  }
  return 0;
}
