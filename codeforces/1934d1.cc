#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n, m;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    int first_one = 0, second_one = -1;
    for (int i = 63; i >= 0; i--) {
      if (n & (1LL << i)) {
        if (first_one) {
          second_one = i;
          break;
        } else
          first_one = i;
      }
    }
    int m_first_one = 0;
    for (int i = 63; i >= 0; i--) {
      if (m & (1LL << i)) {
        m_first_one = i;
        break;
      }
    }
    if (m_first_one == first_one) {
      cout << "1\n" << n << " " << m << "\n";
      continue;
    }
    if (m_first_one > second_one) {
      cout << "-1\n";
      continue;
    }
    if (m_first_one == second_one) {
      cout << "1\n" << n << " " << m << "\n";
      continue;
    }
    cout << "2\n";
    cout << n << " " << (m | (1ll << second_one)) << " " << m << "\n";
  }
  return 0;
}
