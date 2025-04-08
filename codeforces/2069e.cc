#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
using namespace std;

bool haerin(string& s, int a, int b, int ab, int ba) {
  string extended_s = s + s.back();
  int n = extended_s.size(), last = 0, eq_pairs = 0;
  vector<int> rem_ab, rem_ba;
  for (int i = 1; i < n; i++) {
    if (extended_s[i] != extended_s[i - 1]) continue;
    if (s[i - 1] == s[last]) {
      eq_pairs += (i - last) / 2;
    }
    else {
      if (s[last] == 'A') rem_ab.push_back(i - last);
      else rem_ba.push_back(i - last);
    }
    last = i;
  }
  debug(rem_ab, rem_ba, eq_pairs);

  auto chaewon = [&](vector<int>& rem, int& tot) -> int {
    int res = 0;
    sort(rem.rbegin(), rem.rend());
    debug(rem, tot);
    int cnt = 0;
    while (!rem.empty() and tot > 0) {
      int x = min(rem.back() / 2, tot);
      tot -= x;
      res += x;
      rem.back() -= 2 * x;
      if (rem.back() == 0) rem.pop_back();
      // if (++cnt < 10) debug(rem, tot);
    }
    return res;
    };

  auto kazuha = [&](vector<int>& rem, int& tot) -> int {
    int res = 0;
    while (!rem.empty() and tot > 0) {
      int x = min((rem.back() - 2) / 2, tot);
      tot -= x;
      res += x;
      rem.pop_back();
    }
    return res;
    };

  int completed_pairs = 0;
  completed_pairs += chaewon(rem_ab, ab);
  debug(completed_pairs, rem_ab, ab);
  completed_pairs += chaewon(rem_ba, ba);
  completed_pairs += kazuha(rem_ab, ba);
  debug(completed_pairs, rem_ba, ab);
  completed_pairs += kazuha(rem_ba, ab);

  int remaining_pairs = min(eq_pairs, ab + ba);
  debug(completed_pairs, remaining_pairs);
  completed_pairs += remaining_pairs;

  int needed_a = count(s.begin(), s.end(), 'A') - completed_pairs;
  int needed_b = count(s.begin(), s.end(), 'B') - completed_pairs;
  if (needed_a > a or needed_b > b) {
    return false;
  }
  return true;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, a, b, ab, ba;
  string s;
  cin >> t;
  while (t--) {
    cin >> s >> a >> b >> ab >> ba;
    if (haerin(s, a, b, ab, ba)) {
      cout << "YES\n";
    }
    else {
      cout << "NO\n";
    }
  }
  return 0;
}
