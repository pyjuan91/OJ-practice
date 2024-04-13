#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s;
  cin >> s;
  int cnt[26] = {};
  for (char c : s) cnt[c - 'a']++;
  // for(int i=0; i<26; i++) cout << cnt[i] << ' ';  
  // cout << '\n';
  map<int, int> mp;
  for (int i = 0; i < 26; i++) mp[cnt[i]]++;
  for (auto [k, v] : mp) {
    if(k == 0) continue;
    if (v != 2) {
      cout << "No";
      return 0;
    }
  }
  cout << "Yes";
  return 0;
}
