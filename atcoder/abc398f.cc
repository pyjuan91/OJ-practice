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
  string s, t;
  cin >> s;
  t = s;
  reverse(t.begin(), t.end());
  if (t == s) {
    cout << s;
    return 0;
  }
  t += "#" + s;
  vector<int> lps(t.size(), 0);
  for (int i = 1; i < t.size(); i++) {
    int j = lps[i - 1];
    while (j > 0 and t[i] != t[j]) j = lps[j - 1];
    if (t[i] == t[j]) j++;
    lps[i] = j;
  }
  cout << s.substr(0, s.size() - lps.back());
  reverse(s.begin(), s.end());
  cout << s;
  return 0;
}
