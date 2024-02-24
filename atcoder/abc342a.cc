#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s;
  cin >> s;
  map<char, int> mp;
  for (int i = 0; i < s.size(); i++) {
    mp[s[i]]++;
  }
  char odd;
  for (auto i : mp)
    if (i.second == 1) odd = i.first;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == odd) cout << i + 1 << " ";
  }
  return 0;
}
