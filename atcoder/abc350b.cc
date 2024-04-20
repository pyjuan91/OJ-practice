#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m, x;
  cin >> n >> m;
  vector<int> cnt(1001);
  while (m--) {
    cin >> x;
    cnt[x] ^= 1;
  }
  int minus = 0;
  for (auto x : cnt) minus += x;
  cout << n - minus << '\n';
  return 0;
}
