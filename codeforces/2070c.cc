#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;

int haerin(int n, int k, string& s, vector<int>& a) {
  int segments = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'B') {
      segments++;
      while (i < n && s[i] == 'B') {
        i++;
      }
      i--;
    }
  }
  if (segments <= k) {
    return 0;
  }
  debug(segments);
  int left = 0, right = 1e9;
  while (left + 1 < right) {
    int mid = (left + right) / 2;
    int cnt = 0;
    char cur_turn = 'R';
    for (int i = 0; i < n; i++) {
      if (s[i] == cur_turn or a[i] <= mid) continue;
      cur_turn = (cur_turn == 'R' ? 'B' : 'R');
      cnt += cur_turn == 'B';
    }
    debug(mid, cnt, k);
    if (cnt > k) {
      left = mid;
    }
    else {
      right = mid;
    }
  }
  return right;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n, k;
  string s;
  cin >> t;
  while (t--) {
    cin >> n >> k >> s;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    cout << haerin(n, k, s, a) << '\n';

  }
  return 0;
}
