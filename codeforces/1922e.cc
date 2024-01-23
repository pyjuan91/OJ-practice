#include <bits/stdc++.h>
#define int long long
using namespace std;
void chaewon(int n) {
  // generate leading 2's power
  auto custom_log2 = [&](int n) {
    int res = 0;
    while (n) {
      n >>= 1;
      res++;
    }
    return res - 1;
  };
  int l = custom_log2(n);
  vector<int> res;
  for (int i = 1; i <= l; i++) {
    // cout << i << " ";
    res.push_back(i);
  }
  // generate remaining numbers;
  n -= (1ll << l);
  while (n) {
    int l = custom_log2(n);
    // cout << l + 1 << " ";
    res.push_back(l + 1);
    n -= (1ll << l);
  }
  cout << res.size() << "\n";
  for (auto i : res) {
    cout << i << " ";
  }
  cout << "\n";
}
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    chaewon(n);
  }
  return 0;
}
