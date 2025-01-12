#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;

int haerin(int n, int k, vector<int>& a, vector<int>& b) {
  vector<pair<int, int>> c(n);
  set<int> prices;
  for (int i = 0; i < n; i++) {
    c[i] = { a[i], b[i] };
    prices.insert(a[i]);
    prices.insert(b[i]);
  }
  sort(c.begin(), c.end(), [&](const pair<int, int>& x, const pair<int, int>& y) {
    return x.second < y.second;
    });
  int buying_cnt = 0, cur_price, ans = 0, negative_reviews = 0;
  priority_queue<int> positive_threshold;
  while (!prices.empty()) {
    cur_price = *prices.rbegin();
    prices.erase(cur_price);
    while (!c.empty() and c.back().second >= cur_price) {
      negative_reviews++;
      buying_cnt++;
      positive_threshold.push(c.back().first);
      c.pop_back();
    }
    while (!positive_threshold.empty() and positive_threshold.top() >= cur_price) {
      negative_reviews--;
      positive_threshold.pop();
    }
    if (negative_reviews <= k) {
      ans = max(ans, buying_cnt * cur_price);
    }
  }
  return ans;
}

int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int t, n, k;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    cout << haerin(n, k, a, b) << '\n';
  }
  return 0;
}
