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
  int n, x;
  map<int, vector<int>> mp;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    mp[x].push_back(i);
  }
  for (auto it = mp.rbegin(); it != mp.rend(); it++) {
    if (it->second.size() == 1) {
      cout << it->second[0];
      return 0;
    }
  }
  cout << "-1";
  return 0;
}
