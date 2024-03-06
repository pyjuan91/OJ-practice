#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n, c;
  cin >> t;
  while (t--) {
    cin >> n >> c;
    vector<int> s(n);
    for (auto& x : s) cin >> x;
    int total = (c + 2) * (c + 1) / 2, even_cnt = 0, odd_cnt = 0;
    int plus_eq = 0, minus_eq = 0, both_eq = 0;
    for (auto& x : s) {
      plus_eq += x / 2 + 1;
      minus_eq += (c - x + 1);
      even_cnt += (x % 2 == 0);
      odd_cnt += (x % 2 == 1);
    }
    // cout << plus_eq << " " << minus_eq << "\n";
    both_eq = even_cnt * (even_cnt + 1) / 2 + odd_cnt * (odd_cnt + 1) / 2;
    // cout << both_eq << "\n";
    cout << total - plus_eq - minus_eq + both_eq << "\n";
  }
  return 0;
}
