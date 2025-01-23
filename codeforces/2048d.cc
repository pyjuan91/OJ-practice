#include <bits/stdc++.h>
#ifndef ONLINE_JUDGE
#include "./debug.cc"
#else
#define debug(...)
#define debugArr(...)
#endif
#define int long long
using namespace std;
int32_t main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int t, n, m;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;
    int kevin = a[0];
    sort(a.begin(), a.end()), sort(b.begin(), b.end());
    int kevin_rank = n - (lower_bound(a.begin(), a.end(), kevin) - a.begin());
    // debug(a, b, kevin, kevin_rank);
    vector<int> each_can_be_solved;
    for (auto& x : b) {
      int rank = n - (lower_bound(a.begin(), a.end(), x) - a.begin());
      if (rank == 0) rank = n;
      each_can_be_solved.push_back(rank);
    }
    // sort(each_can_be_solved.begin(), each_can_be_solved.end());
    vector<int> contribute_to_rank_sum;
    for (auto& x : each_can_be_solved) {
      if (x < kevin_rank) {
        contribute_to_rank_sum.push_back(x);
      }
      else {
        contribute_to_rank_sum.push_back(0);
      }
    }
    // debug(each_can_be_solved);
    // debug(contribute_to_rank_sum);
    sort(contribute_to_rank_sum.begin(), contribute_to_rank_sum.end());
    // debug(contribute_to_rank_sum);

    for (int i = 1; i <= m; i++) {
      int ans = m / i;
      for (int j = 0; j + i - 1 < m; j += i) {
        ans += contribute_to_rank_sum[j + i - 1];
      }
      cout << ans << ' ';
    }
    cout << '\n';
  }
  return 0;
}
