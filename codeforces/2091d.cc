#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;

bool kang(int mid, int n, int m, int k) {
  int bench_cnt = m / (mid + 1);
  int row_seats = bench_cnt * (mid)+(m % (mid + 1));
  return row_seats * n >= k;
}

int haerin(int n, int m, int k) {
  int left = 0, right = m;
  while (left + 1 < right) {
    int mid = (left + right) / 2;
    if (kang(mid, n, m, k)) {
      right = mid;
    }
    else {
      left = mid;
    }
  }
  return right;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n, m, k;
  cin >> t;
  while (t--) {
    cin >> n >> m >> k;
    cout << haerin(n, m, k) << "\n";
  }
  return 0;
}
