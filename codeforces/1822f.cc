#include <bits/stdc++.h>
using namespace std;
#define int long long
void chaewon(vector<vector<int>>& route, vector<int>& dis, int cur, int prev, int& leaf) {
	for (auto child : route[cur]) {
		if (child != prev) {
			dis[child] = dis[cur] + 1;
			chaewon(route, dis, child, cur, leaf);
		}
	}
	if (dis[cur] > dis[leaf]) leaf = cur;
}
signed main() {
	cin.tie()->sync_with_stdio(false);
	int t, n, k, c, a, b;
	cin >> t;
	while (t--) {
		cin >> n >> k >> c;
		vector<vector<int>> route(n + 1);
		for (int i = 1; i < n; i++) {
			cin >> a >> b;
			route[a].emplace_back(b);
			route[b].emplace_back(a);
		}

		vector<int> dis_from_one(n + 1), dis_from_d1(n + 1),
		  dis_from_d2(n + 1);

		int d1 = 0, d2 = 0, res = 0;
		chaewon(route, dis_from_one, 1, 0, d1);
		chaewon(route, dis_from_d1, d1, 0, d2);
		chaewon(route, dis_from_d2, d2, 0, d1);

		for (int i = 1; i <= n; i++) {
			auto cost = dis_from_one[i] * c;
			auto gain = max(dis_from_d1[i], dis_from_d2[i]) * k;
			res = max(res, gain - cost);
		}

		cout << res << "\n";
	}
	return 0;
}