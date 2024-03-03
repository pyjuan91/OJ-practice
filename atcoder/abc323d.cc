#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, s, c;
  map<int, int> m;
  cin >> n;
  while (n--) {
    cin >> s >> c;
    m[s] += c;
  }
  int res = 0;
  while (!m.empty()) {
    auto it = m.begin();
    int cur_size = it->first, cur_count = it->second;
    while (cur_count > 1) {
      res += cur_count % 2;
      cur_count = cur_count / 2;
      cur_size *= 2;
      // ::cout << cur_size << " " << cur_count << " " << res << endl;
      if (cur_size <= 1e9 && m.count(cur_size)) {
        cur_count += m[cur_size];
        m.erase(cur_size);
      } else if (cur_size > 1e9) {
        while (cur_count > 1) {
          res += cur_count % 2;
          cur_count = cur_count / 2;
        }
      }
    }
    res += cur_count;
    m.erase(it);
  }
  ::cout << res;
  return 0;
}
