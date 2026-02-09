#include <bits/stdc++.h>
#ifdef LOCAL
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;

void patty(int n, int l, int r) {
  vector<int> prefix_xor(n + 1);
  iota(prefix_xor.begin(), prefix_xor.end(), 0LL);
  prefix_xor[r] = prefix_xor[l - 1];
  for (int i = 1; i <= n; i++)
    cout << (prefix_xor[i] xor prefix_xor[i - 1]) << " ";
  cout << "\n";
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n, l, r;
  cin >> t;
  while (t--) {
    cin >> n >> l >> r;
    patty(n, l, r);
  }
  return 0;
}
