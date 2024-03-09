#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  string s;
  cin >> s;
  int n = s.size();
  int first = s.find('|');
  int second = s.rfind('|');
  string result = s.substr(0, first) + s.substr(second + 1, n - second - 1);
  cout << result << endl;
  return 0;
}