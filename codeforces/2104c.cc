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
  int t, n;
  string s;
  cin >> t;
  while (t--) {
    cin >> n >> s;
    vector<int> alice, bob;
    for (int i = 0; i < n; i++) {
      if (s[i] == 'A') {
        alice.push_back(i);
      }
      else {
        bob.push_back(i);
      }
    }

    if (n == 2) {
      if (s[0] == 'A') {
        cout << "Alice\n";
      }
      else {
        cout << "Bob\n";
      }
      continue;
    }

    if (alice.size() == 1) {
      cout << "Bob\n";
      continue;
    }

    if (bob.size() == 1) {
      cout << "Alice\n";
      continue;
    }

    if (s[n - 1] == 'A' and s[n - 2] == 'A') {
      cout << "Alice\n";
      continue;
    }

    if (s[n - 1] == 'A' and s[0] == 'A') {
      cout << "Alice\n";
      continue;
    }
    
    cout << "Bob\n";
  }
  return 0;
}
