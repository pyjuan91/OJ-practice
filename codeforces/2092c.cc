#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    int max_odd = -1, even_sum = 0, odd_sum = 0, odd_cnt = 0, even_cnt = 0;
    vector<int> a(n);
    for (auto& x : a) {
      cin >> x;
      if (x % 2 == 0) {
        even_sum += x;
        even_cnt++;
      }
      else {
        odd_sum += x;
        odd_cnt++;
        max_odd = max(max_odd, x);
      }
    }
    if (odd_cnt == 0 or even_cnt == 0) {
      cout << *max_element(a.begin(), a.end()) << '\n';
    }
    else {
      odd_sum -= max_odd;
      even_sum += odd_sum - (odd_cnt - 1);
      cout << max_odd + even_sum << '\n';
    }
  }
  return 0;
}
