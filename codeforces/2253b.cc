#include <bits/stdc++.h>
#ifdef LOCAL
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;

int chaewon(int n, vector<int>& a) {
  int removed = 0;
  vector<pair<int, int>> blocks = {make_pair(a[0], 1)};
  for (int i = 1; i < n; i++) {
    if (a[i] == a[i - 1]) {
      removed++;
      blocks.back().second++;
    } else {
      blocks.push_back(make_pair(a[i], 1));
    }
  }
  // debug(removed);
  // debug(blocks);

  // adjacent two blocks
  for (int i = 1; i < blocks.size(); i++) {
    if (blocks[i].second >= 2 and blocks[i - 1].second >= 2) {
      return n - removed + 2;
    }
  }

  bool one_buffer = false;
  for (int i = 0; i < blocks.size(); i++) {
    if (blocks[i].second >= 2 and
        (i + 2 == blocks.size() or
         i + 2 < blocks.size() and blocks[i].first != blocks[i + 2].first))
      one_buffer = true;
    if (blocks[i].second >= 2 and
        (i - 2 == -1 or i - 2 >= 0 and blocks[i - 2].first != blocks[i].first))
      one_buffer = true;
  }

  if (one_buffer) return n - removed + 1;
  return n - removed;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    cout << chaewon(n, a) << "\n";
  }
  return 0;
}
