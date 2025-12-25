#include <bits/stdc++.h>
#ifdef LOCAL
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;

string patty(int n, vector<int>& a) {
  int sum = accumulate(a.begin(), a.end(), 0);
  for (const auto& x : a) {
    if (x > sum / 2) return "T";
  }
  if (sum % 2 == 0) return "HL";
  return "T";
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    cout << patty(n, a) << "\n";
  }
  return 0;
}
