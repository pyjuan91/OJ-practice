#include <bits/stdc++.h>
using namespace std;
void remove_edge(vector<vector<int>> &adj, int i, int j) {
	for (auto &child : adj[i]) {
		if (child == j) {
			swap(child, adj[i].back());
			adj[i].pop_back();
			return;
		}
	}
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, m, a, b;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		vector<vector<int>> adj(n + 1);
		vector<bool> visited(n + 1, false);
		queue<int> q;
		int connected = 0;
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			adj[a].emplace_back(b);
			adj[b].emplace_back(a);
		}
		int four_num = 0, two_num = 0, k = sqrt(n);
		for (int i = 1; i <= n; i++) {
			if (adj[i].size() != 2 && adj[i].size() != 4) {
				cout << "NO\n";
				goto end;
			}
		}
		if (n < 9 || k * k != n || n + k != m) {
			cout << "NO\n";
			continue;
		}
		
		q.push(1);
		visited[1] = true;
		while(!q.empty()) {
			int cur = q.front();
			q.pop();
			connected +=1;
			for (auto child : adj[cur]) {
				if (!visited[child]) {
					visited[child] = true;
					q.push(child);
				}
			}
		}
		visited = vector<bool>(n + 1, false);
		if(connected != n) {
			cout << "NO\n";
			goto end;
		}
		for (int i = 1; i <= n; i++) {
			if (adj[i].size() == 2) continue;
			for (int j = 0; j < adj[i].size(); j++) {
				int neighbor = adj[i][j];
				if (adj[neighbor].size() > 2) {
					remove_edge(adj, i, neighbor);
					remove_edge(adj, neighbor, i);
					j--;
				}
			}
		}

		for (int i = 1; i <= n; i++) {
			if (visited[i]) continue;
			visited[i] = true;
			q.push(i);
			int cyc_len = 0;
			while (!q.empty()) {
				int cur = q.front();
				q.pop();
				cyc_len++;
				for (auto child : adj[cur]) {
					if (!visited[child]) {
						visited[child] = true;
						q.push(child);
					}
				}
			}
			if (cyc_len != k) {
				cout << "NO\n";
				goto end;
			}
		}
		cout << "YES\n";
	end:;
	}
	return 0;
}