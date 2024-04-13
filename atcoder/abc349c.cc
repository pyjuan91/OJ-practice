#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s, t;
  cin >> s >> t;
  int cur_check = 0;
  for (auto c : s) {
    c = toupper(c);
    if (c == t[cur_check]) cur_check++;
    if (cur_check == t.size()) {
      cout << "Yes";
      return 0;
    }
  }
  if (cur_check == 2 && t[2] == 'X') {
    cout << "Yes";
    return 0;
  }
  cout << "No";
  return 0;
}
