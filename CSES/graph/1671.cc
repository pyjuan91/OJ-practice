#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, a, b, c;
	cin >> n >> m;
	vector<vector<pair<int, int>>> adj(n + 1);
	vector<int> dist(n + 1, (int)1e18);
	while (m--) {
		cin >> a >> b >> c;
		adj[a].emplace_back(make_pair(b, c));
	}
	dist[1] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({1, 0});
	while (!q.empty()) {
		auto p = q.top();
		q.pop();
		int cur_node = p.first, cur_dist = p.second;
		if (cur_dist > dist[cur_node]) continue;
		for (auto child : adj[cur_node]) {
			int child_node = child.first, child_dist = child.second;
			if (cur_dist + child_dist < dist[child_node]) {
				dist[child_node] = cur_dist + child_dist;
				q.push({child_node, dist[child_node]});
			}
		}
	}
    for(int i=1;i<=n;i++) cout << dist[i] << " ";
	return 0;
}