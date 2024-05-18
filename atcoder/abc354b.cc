#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<string> s(n);
  int sum = 0, x;
  for (int i = 0; i < n; i++) {
    cin >> s[i] >> x;
    sum += x;
  }
  sort(s.begin(), s.end());
  cout << s[sum % n] << '\n';
  return 0;
}
