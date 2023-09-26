#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
int n, m, a, b, c, res[maxn], prev_node[maxn] = {};
vector<pair<int, int>> g[maxn];
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < maxn; i++) res[i] = 1e18;
	while (m--) {
		cin >> a >> b >> c;
		g[a].emplace_back(b, c);
		g[b].emplace_back(a, c);
	}
	auto cmp = [](pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
	};
	priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
	pq.push({1, 0});
	res[1] = 0;
	while (!pq.empty()) {
		auto [node, weight] = pq.top();
		pq.pop();
		for (auto [nxt, nxt_weight] : g[node]) {
			if (weight + nxt_weight < res[nxt]) {
				res[nxt] = weight + nxt_weight;
				prev_node[nxt] = node;
				pq.push({nxt, res[nxt]});
			}
		}
	}
	vector<int> ans;
	int cur_node = n;
	while (cur_node != 0) {
		ans.push_back(cur_node);
		cur_node = prev_node[cur_node];
	}
	if (ans.size() == 1) cout << "-1";
	else {
		reverse(ans.begin(), ans.end());
		for (auto x : ans) cout << x << " ";
	}
	return 0;
}
