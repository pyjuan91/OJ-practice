#include <bits/stdc++.h>
#ifdef LOCAL
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;

void patty(int expo) {
  int n = (1LL << expo);
  vector<int> a = {n - 1, (n - 1) >> 1};
  debug(a);
  for (int bit_shift = 2, free_digs = 1; ((n - 1) >> bit_shift) > 0;
       bit_shift++, free_digs++) {
    for (int left_buff = 0; left_buff < (1LL << free_digs); left_buff++) {
      debug(left_buff);
      int num = (left_buff << (expo - bit_shift + 1)) | ((n - 1) >> bit_shift);
      debug(num);
      a.push_back(num);
    }
    debug(a);
  }
  if (n > 2)
    for (int i = 0; i < n; i += 2) a.push_back(i);
  for (const auto& x : a) cout << x << " ";
  cout << "\n";
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    patty(n);
  }
  return 0;
}
