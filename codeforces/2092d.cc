#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;

char missing_char(char a, char b) {
  if ((a == 'L' && b == 'I') || (a == 'I' && b == 'L')) return 'T';
  if ((a == 'L' && b == 'T') || (a == 'T' && b == 'L')) return 'I';
  if ((a == 'I' && b == 'T') || (a == 'T' && b == 'I')) return 'L';
  return '?';
}

bool is_balanced(const string& s) {
  if (s.size() % 3 != 0) return false;
  int cnt_l = 0, cnt_i = 0, cnt_t = 0;
  for (char c : s) {
    if (c == 'L') cnt_l++;
    else if (c == 'I') cnt_i++;
    else cnt_t++;
  }
  return (cnt_l == cnt_i and cnt_i == cnt_t);
}

tuple<int, int, int> count_chars(const string& s) {
  int cnt_l = 0, cnt_i = 0, cnt_t = 0;
  for (char c : s) {
    if (c == 'L') cnt_l++;
    else if (c == 'I') cnt_i++;
    else if (c == 'T') cnt_t++;
  }
  return { cnt_l, cnt_i, cnt_t };
}

void haerin(int n, string& s) {
  auto [cnt_l, cnt_i, cnt_t] = count_chars(s);
  if (cnt_l == n or cnt_i == n or cnt_t == n) {
    cout << -1 << "\n";
    return;
  }
  if (is_balanced(s)) {
    cout << 0 << "\n";
    return;
  }
  vector<int> ops;
  int max_op = 2 * n;
  for (int op = 0; op < max_op; op++) {
    if (is_balanced(s)) {
      break;
    }
    int cnt_l, cnt_i, cnt_t;
    tie(cnt_l, cnt_i, cnt_t) = count_chars(s);
    char target;
    if (cnt_l <= cnt_i and cnt_l <= cnt_t) target = 'L';
    else if (cnt_i <= cnt_l and cnt_i <= cnt_t) target = 'I';
    else target = 'T';
    bool kang = false;
    for (int i = 0; i < s.size() - 1; i++) {
      if (s[i] == s[i + 1]) continue;
      char forced = missing_char(s[i], s[i + 1]);
      if (forced == target) {
        s.insert(s.begin() + i + 1, forced);
        ops.push_back(i + 1);
        kang = true;
        break;
      }
    }
    if (!kang) {
      for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] != s[i + 1]) {
          char forced = missing_char(s[i], s[i + 1]);
          s.insert(s.begin() + i + 1, forced);
          ops.push_back(i + 1);
          break;
        }
      }
    }
  }
  if (is_balanced(s)) {
    cout << ops.size() << "\n";
    for (auto pos : ops) cout << pos << "\n";
  }
  else {
    cout << -1 << "\n";
  }
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n;
  string s;
  cin >> t;
  while (t--) {
    cin >> n >> s;
    haerin(n, s);
  }
  return 0;
}
