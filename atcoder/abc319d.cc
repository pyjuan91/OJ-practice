#include <bits/stdc++.h>
#define int long long
using namespace std;

bool zuha(int n, int m, vector<int>& a, int width) {
  int lines = 1, cur_line = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] > width) return false;
    if (cur_line == 0) {
      cur_line = a[i];
    } else {
      if (cur_line + a[i] + 1 <= width) {
        cur_line += a[i] + 1;
      } else {
        lines++;
        cur_line = a[i];
      }
    }
  }
  return lines <= m;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (auto& i : a) cin >> i;
  int left = 0, right = 1e16, mid;
  while (left + 1 < right) {
    mid = (left + right) / 2;
    if (zuha(n, m, a, mid))
      right = mid;
    else
      left = mid;
  }
  cout << right << '\n';
  return 0;
}
