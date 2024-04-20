#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s;
  cin >> s;
  if (s.substr(0, 3) != "ABC") {
    cout << "No\n";
    return 0;
  }
  int n = atoi(s.substr(3).c_str());
  if (n <= 349 && n != 316 && n >= 1) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
  return 0;
}
