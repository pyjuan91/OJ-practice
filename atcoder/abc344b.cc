#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  vector<int> a;
  int x;
  while (cin >> x) {
    a.push_back(x);
    if (x == 0) break;
  }
  reverse(a.begin(), a.end());
  for (auto x : a) cout << x << "\n";
  return 0;
}
