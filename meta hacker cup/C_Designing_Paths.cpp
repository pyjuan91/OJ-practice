#include <bits/stdc++.h>
#ifdef LOCAL
#	include "./debug.cc"
#else
#	define debug(...)
#	define debugArr(...)
#endif
#define int long long
using namespace std;

int patty() {
	int n, k, m;
	cin >> n >> k >> m;

	vector<vector<int>> routes(m);
	// {{route_id, stop_id}}
	vector<vector<pair<int, int>>> which_route_which_stop(n + 1);

	vector<vector<bool>> visited_route_stop(m);

	for (int i = 0; i < m; ++i) {
		int len;
		cin >> len;
		routes[i].resize(len);
		visited_route_stop[i].resize(len, false);
		for (int j = 0; j < len; ++j) {
			cin >> routes[i][j];
			which_route_which_stop[routes[i][j]].push_back({i, j});
		}
	}

	queue<int> q;
	vector<int> dist(n + 1, -1);

	q.push(1);
	dist[1] = 0;

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		int cur_dist = dist[u];

		for (const auto& [route_id, stop_idx] : which_route_which_stop[u]) {

			int route_len = routes[route_id].size();
			for (int s = 1; s <= k && stop_idx + s < route_len; s++) {
				int next_stop_idx = stop_idx + s;
				if (visited_route_stop[route_id][next_stop_idx]) {
					break;
				}
				visited_route_stop[route_id][next_stop_idx] = true;

				int v = routes[route_id][next_stop_idx];

				if (dist[v] == -1) {
					dist[v] = cur_dist + 1;
					q.push(v);
				}
			}
		}
	}

	int res = 0;
	for (int i = 1; i <= n; ++i) {
		res += dist[i] * i;
	}
	return res;
}

int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	for (int kase = 1; kase <= t; kase++) {
		int res = patty();
		cout << "Case #" << kase << ": " << res << "\n";
	}
	return 0;
}
