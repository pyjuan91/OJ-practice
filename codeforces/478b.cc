#include <bits/stdc++.h>
#ifdef LOCAL
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  // min friend pair = (avg, avg, avg, ...)
  int min_base = n / m, min_remain = n % m;
  auto get_fp = [&](int x) -> int { return x * (x - 1) / 2; };
  int min_fp =
      min_remain * get_fp(min_base + 1) + (m - min_remain) * get_fp(min_base);
  int max_fp = get_fp(n - m + 1);
  cout << min_fp << " " << max_fp << "\n";
  return 0;
}
