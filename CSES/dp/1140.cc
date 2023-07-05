#include <bits/stdc++.h>
#define int long long
using namespace std;
int get_id(auto& ib, auto tar) {
	return lower_bound(ib.begin(), ib.end(), tar) - ib.begin() + 1;
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, a, b, p, last_consid = 0, lid = 0, res = 0;
	cin >> n;
	vector<int> interval_bounds, dp = {0};
	vector<vector<int>> pros;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> p;
		pros.push_back({a, b, p});
		interval_bounds.emplace_back(a);
		interval_bounds.emplace_back(b);
	}
	sort(pros.begin(), pros.end(), [&](auto l, auto r) {
		return l[0] < r[0];
	});
	sort(interval_bounds.begin(), interval_bounds.end());
	interval_bounds.resize(distance(
	  interval_bounds.begin(),
	  unique(interval_bounds.begin(), interval_bounds.end())));
	for (int i = 0; i < n; i++) {
		auto s = pros[i][0], e = pros[i][1], p = pros[i][2];

		auto sid = get_id(interval_bounds, s),
			 eid = get_id(interval_bounds, e);

		while (lid < sid) {
			dp[lid] = last_consid = max(last_consid, dp[lid]), lid++;
		}
		while (dp.size() <= (size_t) eid)
			dp.push_back(dp[dp.size() - 1]);
		dp[eid] = max(dp[eid], last_consid + p);
		res = max(res, dp[eid]);
	}
	cout << res;
	return 0;
}