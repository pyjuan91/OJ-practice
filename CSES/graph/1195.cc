#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>
#define mp make_pair
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, a, b, c;
	cin >> n >> m;
	vector<vector<pii>> adj(n + 1);
	vector<vector<int>> dist(n + 1, vector<int>(2, INT64_MAX));
	priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
	while (m--) {
		cin >> a >> b >> c;
		adj[a].emplace_back(mp(c, b));
	}
	dist[1][0] = dist[1][1] = 0;
	pq.push(mp(0, mp(1, 0)));
	while (!pq.empty()) {
		auto cost = pq.top().first, pos = pq.top().second.first,
			 type = pq.top().second.second;
		pq.pop();
		if (dist[pos][type] < cost) continue;
		for (auto& [c, p] : adj[pos]) {
			if (type == 0) {
				if (dist[p][1] > cost + c / 2) {
					dist[p][1] = cost + c / 2;
					pq.push(mp(dist[p][1], mp(p, 1)));
				}
				if (dist[p][0] > cost + c) {
					dist[p][0] = cost + c;
					pq.push(mp(dist[p][0], mp(p, 0)));
				}
			}
			else if (dist[p][1] > cost + c) {
				dist[p][1] = cost + c;
				pq.push(mp(dist[p][1], mp(p, 1)));
			}
		}
	}
	cout << dist[n][1] << '\n';
	return 0;
}