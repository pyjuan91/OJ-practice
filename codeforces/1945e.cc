#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n, m;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    vector<int> pos(n + 1), a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      pos[a[i]] = i;
    }
    vector<bool> lower_eq(n + 1, false), upper(n + 1, false);
    int left = 1, right = n + 1;
    while (left + 1 < right) {
      int mid = (left + right) / 2;
      if (a[mid] <= m) {
        lower_eq[mid] = true;
        left = mid;
      } else {
        upper[mid] = true;
        right = mid;
      }
    }
    if (a[left] == m) {
      cout << "0\n";
      continue;
    }

    auto get_unused_smaller = [&]() {
      for (int i = 1; i < m; i++) {
        if (!lower_eq[i]) {
          return i;
        }
      }
      return -1LL;
    };

    auto get_unused_larger = [&]() {
      for (int i = m + 1; i <= n; i++) {
        if (!upper[i]) {
          return i;
        }
      }
      return -1LL;
    };

    int m_pos = pos[m];
    if (lower_eq[m_pos]) {
      if (a[left] < m) {
        cout << "1\n";
        cout << left << " " << m_pos << "\n";
      } else {
        int unused_smaller = get_unused_smaller();
        cout << "2\n";
        cout << m_pos << " " << pos[unused_smaller] << "\n";
        cout << pos[unused_smaller] << " " << left << "\n";
      }
    } else {
      cout << "1\n";
      cout << m_pos << " " << left << "\n";
    }
  }
  return 0;
}
