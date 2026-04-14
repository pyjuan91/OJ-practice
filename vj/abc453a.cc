#include <bits/stdc++.h>
#ifdef LOCAL
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  string s;
  cin >> n >> s;
  deque<char> dq(s.begin(), s.end());
  while (!dq.empty() and dq.front() == 'o') dq.pop_front();
  string res(dq.begin(), dq.end());
  cout << res << "\n";
  return 0;
}
