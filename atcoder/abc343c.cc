#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 1e6; i >= 1; i--) {
    if (i * i * i > n) continue;
    auto check_palindrome = [&](int x) {
      string s = to_string(x);
      for (int i = 0; i < s.size() / 2; i++) {
        if (s[i] != s[s.size() - i - 1]) return false;
      }
      return true;
    };
    if (check_palindrome(i * i * i)) {
      cout << i * i * i << '\n';
      return 0;
    }
  }
  return 0;
}
