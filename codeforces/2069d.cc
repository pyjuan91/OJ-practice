#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
using namespace std;

int haerin(string& s) {
  deque<char> dq(s.begin(), s.end());
  while (!dq.empty() and dq.front() == dq.back()) dq.pop_front(), dq.pop_back();
  if (dq.empty()) return 0;
  int n = dq.size(), left = 0, right = n - 1;
  while (left + 1 < right) {
    int mid = (left + right) / 2;
    bool prefix_ok = true;

    vector<int> cnt_prefix(26);
    for (int i = 0; i < mid; i++) cnt_prefix[dq[i] - 'a']++;
    for (int i = 0; i < mid; i++) {
      if (n - 1 - i >= mid) { 
          cnt_prefix[dq[n - 1 - i] - 'a']--;
          if (cnt_prefix[dq[n - 1 - i] - 'a'] < 0) {
              prefix_ok = false;
              break;
          }
      }
  }
  
    for (int i = mid; i < n / 2; i++) {
      if (dq[i] != dq[n - 1 - i]) {
        prefix_ok = false;
        break;
      }
    }
    if (prefix_ok) {
      right = mid;
    }
    else {
      left = mid;
    }
  }
  debug(left, right);
  int res = right;
  left = 0, right = n - 1;

  while (left + 1 < right) {
    int mid = (left + right) / 2;
    bool suffix_ok = true;

    vector<int> cnt_suffix(26);
    for (int i = n - 1; i >= n - mid; i--) cnt_suffix[dq[i] - 'a']++;
    for (int i = n - 1; i >= n - mid; i--) {
      if (n - 1 - i < n - mid) {  
          cnt_suffix[dq[n - 1 - i] - 'a']--;
          if (cnt_suffix[dq[n - 1 - i] - 'a'] < 0) {
              suffix_ok = false;
              break;
          }
      }
  }
  
    for (int i = n - mid - 1; i >= n / 2; i--) {
      if (dq[i] != dq[n - 1 - i]) {
        suffix_ok = false;
        break;
      }
    }
    if (suffix_ok) {
      right = mid;
    }
    else {
      left = mid;
    }
  }
  debug(left, right);
  res = min(res, right);
  return res;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t;
  string s;
  cin >> t;
  while (t--) {
    cin >> s;
    cout << haerin(s) << '\n';
  }
  return 0;
}
