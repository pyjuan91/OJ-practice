#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  string s, t;
  cin >> n >> s >> t;

  vector<string> res(n, string(n, '.'));
  bool ok = false;

  auto check_now = [&](int x, int y) {
    // check exact one
    for (int i = 0; i < x; i++) {
      int cnt[3] = {0, 0, 0};
      for (int j = 0; j < n; j++) {
        if (res[i][j] == '.') continue;
        cnt[res[i][j] - 'A']++;
      }
      if (cnt[0] != 1 || cnt[1] != 1 || cnt[2] != 1) return false;
    }
    int cnt[3] = {0, 0, 0};
    for (int j = 0; j <= y; j++) {
      if (res[x][j] == '.') continue;
      cnt[res[x][j] - 'A']++;
    }
    if (cnt[0] > 1 || cnt[1] > 1 || cnt[2] > 1) return false;
    for (int j = 0; j < n; j++) {
      int cnt[3] = {0, 0, 0};
      for (int i = 0; i < n; i++) {
        if (res[i][j] == '.') continue;
        cnt[res[i][j] - 'A']++;
      }
      if (cnt[0] > 1 || cnt[1] > 1 || cnt[2] > 1) return false;
    }
    // check top == t
    for (int j = 0; j < n; j++) {
      for (int i = 0; i < n; i++) {
        if (res[i][j] != '.') {
          if (res[i][j] != t[j]) return false;
          break;
        }
      }
    }
    // check left == s
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (res[i][j] != '.') {
          if (res[i][j] != s[i]) return false;
          break;
        }
      }
    }
    return true;
  };

  auto check_all = [&]() {
    // check exact one
    for (int i = 0; i < n; i++) {
      int cnt[3] = {0, 0, 0};
      for (int j = 0; j < n; j++) {
        if (res[i][j] == '.') continue;
        cnt[res[i][j] - 'A']++;
      }
      if (cnt[0] != 1 || cnt[1] != 1 || cnt[2] != 1) return false;
    }
    for (int j = 0; j < n; j++) {
      int cnt[3] = {0, 0, 0};
      for (int i = 0; i < n; i++) {
        if (res[i][j] == '.') continue;
        cnt[res[i][j] - 'A']++;
      }
      if (cnt[0] != 1 || cnt[1] != 1 || cnt[2] != 1) return false;
    }
    // check top == t
    for (int j = 0; j < n; j++) {
      for (int i = 0; i < n; i++) {
        if (res[i][j] != '.') {
          if (res[i][j] != t[j]) return false;
          break;
        }
      }
    }
    // check left == s
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (res[i][j] != '.') {
          if (res[i][j] != s[i]) return false;
          break;
        }
      }
    }
    return true;
  };

  function<void(int, int)> zuha = [&](int x, int y) {
    if (ok) return;
    if (x == n) {
      if (check_all()) {
        ok = true;
      }
      return;
    }
    if (y == n) {
      zuha(x + 1, 0);
      return;
    }
    zuha(x, y + 1);
    if (ok) return;
    for (int i = 0; i < 3; i++) {
      res[x][y] = 'A' + i;
      if (check_now(x, y)) {
        zuha(x, y + 1);
        if (ok) return;
      }
      res[x][y] = '.';
    }
  };

  zuha(0, 0);
  if (ok) {
    cout << "Yes\n";
    for (int i = 0; i < n; i++) cout << res[i] << '\n';
  } else {
    cout << "No\n";
  }
  return 0;
}
