#include <bits/stdc++.h>
using namespace std;
void chaewon(
  vector<vector<int>>& route, vector<int>& ans,
  vector<bool>& vist, int p, int d) {
	queue<pair<int, int>> q;
	q.push(make_pair(p, d));
	while (!q.empty()) {
		auto front = q.front();
		q.pop();
		auto cp = front.first;
		auto cd = front.second;
		ans[cp] = 0;
		vist[cp] = true;
		if (cd == 0) continue;
		for (auto child : route[cp]) {
			if (vist[child]) continue;
			vist[child] = true;
			ans[cp] = 0;
			q.push(make_pair(child, cd - 1));
		}
	}
}
int main() {
	cin.tie()->sync_with_stdio(false);
	int n, m, k, u, v;
	cin >> n >> m;
	vector<vector<int>> route(n + 1, vector<int>());
	vector<int> ans(n + 1, 1);
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		route[u].emplace_back(v);
		route[v].emplace_back(u);
	}
	cin >> k;
	vector<int> p(k), d(k);
	for (int i = 0; i < k; i++) {
		cin >> p[i] >> d[i];
		if (d[i] == 0) continue;
		vector<bool> vist(n + 1, false);
		chaewon(route, ans, vist, p[i], d[i] - 1);
	}

	bool yes = true;
	queue<int> q;
	vector<int> dis(n + 1, -1);
	for (int i = 1; i <= n; i++) {
		if (ans[i] == 1) {
			q.push(i);
			dis[i] = 0;
		}
	}

	while (!q.empty()) {
		auto p = q.front();
		q.pop();
		for (auto child : route[p]) {
			if (dis[child] == -1) {
				dis[child] = dis[p] + 1;
				q.push(child);
			}
		}
	}

	for (int i = 0; i < k; i++) {
		if (dis[p[i]] != d[i]) {
			yes = false;
			break;
		}
	}

	if (yes) {
		cout << "Yes\n";
		for (int i = 1; i <= n; i++) cout << ans[i];
	}
	else cout << "No";
	return 0;
}