#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, a, b, x;
	cin >> n;
	vector<vector<int>> g(n + 1);
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vector<int> bfs_order(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> x;
		bfs_order[x] = i;
	}
	vector<bool> vis(n + 1, false);
	queue<int> q;
	q.push(1);
	vis[1] = true;
	int index = 1;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vector<int> children;
		for (auto child : g[u]) {
			if (!vis[child]) {
				children.push_back(child);
				vis[child] = true;
			}
		}
		sort(children.begin(), children.end(), [&](int a, int b) {
			return bfs_order[a] < bfs_order[b];
		});
		for (int child : children) {
			if (bfs_order[child] != index + 1) {
				cout << "No\n";
				return 0;
			}
			q.push(child);
			index++;
		}
	}
	cout << "Yes\n";
	return 0;
}
