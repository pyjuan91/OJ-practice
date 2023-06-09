#include <bits/stdc++.h>
#define int long long
const int mod = 1e9 + 7;
using namespace std;
int find_num_route(int node, vector<int>& num_route, vector<vector<int>>& route) {
	if (num_route[node] != -1) return num_route[node];
	int res = 0;
	for (auto x : route[node]) {
		res += find_num_route(x, num_route, route);
		res %= mod;
	}
	return num_route[node] = res;
}
int find_num_node(int node, vector<int>& num_node, vector<vector<int>>& route, bool finding_minimum) {
	if (num_node[node] != -1) return num_node[node];
	int res;
    if(finding_minimum) res = INT64_MAX;
    else res = INT64_MIN;
	for (auto x : route[node]) {
		if (finding_minimum)
			res = min(res, find_num_node(x, num_node, route, true));
		else
			res = max(res, find_num_node(x, num_node, route, false));
	}
	return num_node[node] = res + 1;
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, a, b, c;
	cin >> n >> m;
	vector<vector<pair<int, int>>> adj(n + 1);
	vector<int> dist(n + 1, INT64_MAX);
	vector<vector<int>> route(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		adj[a].push_back({b, c});
	}
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, 1));
	dist[1] = 0;
	while (!pq.empty()) {
		auto p = pq.top();
		pq.pop();
		int cost = p.first, node = p.second;
		if (dist[node] < cost) continue;
		for (auto x : adj[node]) {
			int next = x.first, next_cost = x.second;
			if (dist[next] > cost + next_cost) {
				dist[next] = dist[node] + next_cost;
				pq.push(make_pair(dist[next], next));
				route[next].clear();
				route[next].push_back(node);
			}
			else if (dist[next] == cost + next_cost) {
				route[next].push_back(node);
			}
		}
	}
	vector<int> num_route(n + 1, -1), min_num_node(n + 1, -1),
	  max_num_node(n + 1, -1);
	num_route[1] = 1;
	for (int i = 2; i <= n; i++)
		num_route[i] = find_num_route(i, num_route, route);
	// for (int i = 1; i <= n; i++) cout << num_route[i] << " ";
	// cout << endl;
	min_num_node[1] = max_num_node[1] = 0;
	for (int i = 2; i <= n; i++) {
		min_num_node[i] = find_num_node(i, min_num_node, route, true);
		max_num_node[i] = find_num_node(i, max_num_node, route, false);
	}
    // for(int i=1;i<=n;i++) cout<<min_num_node[i]<<" ";
    // cout << endl;
    // for(int i=1;i<=n;i++) cout<<max_num_node[i]<<" ";
    // cout << endl;
    cout << dist[n] << " " << num_route[n] << " " << min_num_node[n] << " " << max_num_node[n] << endl;
	return 0;
}