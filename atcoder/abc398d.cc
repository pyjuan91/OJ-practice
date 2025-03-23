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
  int n, r, c, x, y;
  cin >> n >> r >> c;
  x = y = 0;
  string s;
  cin >> s;
  set<pair<int, int>> smokes = { {0, 0} };
  for (int i = 0; i < n; i++) {
    if (s[i] == 'N') {
      x++, r++;
    }
    else if (s[i] == 'S') {
      x--, r--;
    }
    else if (s[i] == 'E') {
      y--, c--;
    }
    else {
      y++, c++;
    }
    smokes.insert({ x, y });
    debug(x, y, r, c);
    debug(smokes);
    if (smokes.count({ r, c })) cout << "1";
    else cout << "0";
  }
  return 0;
}
