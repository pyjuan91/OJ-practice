#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m;
	pair<int, int> res;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	auto check = [&](int guess_b) {
		vector<pair<int, int>> mask_set;
		auto contained = [&](int mask) {
			for (auto &i : mask_set) {
				if (i.first == mask) return true;
			}
			return false;
		};
		for (int i = 0; i < n; i++) {
			int mask = 0;
			for (int j = 0; j < m; j++)
				if (a[i][j] >= guess_b) mask |= (1 << j);
			if (!contained(mask))
				mask_set.emplace_back(mask, i);
		}
		int sz = mask_set.size();
		for (int i = 0; i < sz; i++) {
			for (int j = i; j < sz; j++) {
				if ((mask_set[i].first | mask_set[j].first) == (1 << m) - 1)
					return make_pair(
					  mask_set[i].second, mask_set[j].second);
			}
		}
		return make_pair(-1, -1);
	};
	for (auto &i : a)
		for (auto &j : i) cin >> j;
	int left = 0, right = 1e9 + 5, mid;
	while (left + 1 < right) {
		mid = (left + right) / 2;
		res = check(mid);
		if (res.first == -1) right = mid;
		else left = mid;
	}
	res = check(left);
	cout << res.first + 1 << " " << res.second + 1;
	return 0;
}
