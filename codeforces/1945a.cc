#include <bits/stdc++.h>
#define int long long
using namespace std;

int chaewon(int a, int b, int c) {
  if (b % 3 == 1) {
    if (c < 2) return -1;
    c -= 2, b += 2;
  }
  if (b % 3 == 2) {
    if (c < 1) return -1;
    b++, c--;
  }
  int res = a + b / 3;
  res += c / 3;
  if (c % 3) res++;
  return res;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, a, b, c;
  cin >> t;
  while (t--) {
    cin >> a >> b >> c;
    cout << chaewon(a, b, c) << "\n";
  }
  return 0;
}
