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
  int x, y, z;
  cin >> x >> y >> z;
  debug(x, y, z);
  auto out = [&](vector<int>& s) {
    cout << s.size();
    for (const auto& x : s) cout << " " << x;
    cout << "\n";
  };
  if (x == y) {
    vector<int> s1(x, 0);
    vector<int> s2(z, 0);
    vector<int> s3(z, 0);
    out(s1), out(s2), out(s3);
  } else {
    vector<int> s1(y, 0);
    vector<int> s2(z, 1);
    for (int i = 0; i < x; i++) s2.push_back(0);
    vector<int> s3(y, 0);
    for (int i = 0; i < z; i++) s3.push_back(1);
    out(s1), out(s2), out(s3);
  }
  return 0;
}
