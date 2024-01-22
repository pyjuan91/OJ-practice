#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ifstream cin("diamond.in");
  ofstream cout("diamond.out");
  cin.tie(nullptr)->sync_with_stdio(false);
  int n, k, x;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  sort(a.begin(), a.end());
  vector<int> collect_when_select(n);
  for (int i = 0; i < n; i++) {
    int cnt = upper_bound(a.begin(), a.end(), a[i] + k) - a.begin() - i;
    collect_when_select[i] = cnt;
  }
  vector<int> suffix_max(n);
  suffix_max[n - 1] = collect_when_select[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    suffix_max[i] = max(suffix_max[i + 1], collect_when_select[i]);
  }
  int res = suffix_max[0];
  for (int small_bag = 0; small_bag < n - 1; small_bag++) {
    int small_bag_cnt = collect_when_select[small_bag];
    int big_bag_cnt = suffix_max[small_bag + small_bag_cnt];
    res = max(res, small_bag_cnt + big_bag_cnt);
  }
  cout << res << '\n';
  return 0;
}
