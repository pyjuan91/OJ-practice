#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  unordered_map<int, int> mp;
  int n, m, a, b;
  cin >> n >> m;
  vector<int> sc(n + 1);
  mp[0] = n;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    mp[sc[a]]--;
    if (mp[sc[a]] == 0) mp.erase(sc[a]);
    sc[a] += b;
    mp[sc[a]]++;
    cout << mp.size() << '\n';
  }
  return 0;
}
