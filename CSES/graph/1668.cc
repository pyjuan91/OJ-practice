#include <bits/stdc++.h>
using namespace std;
void chaewon(vector<vector<int>>& route, int n) {
	vector<int> res(n + 1);
	for (int i = 1; i <= n; i++) {
		if (res[i] == 0) {
			res[i] = 1;
			queue<int> q;
			q.push(i);
			while (!q.empty()) {
				auto cur = q.front();
				q.pop();
				for (auto child : route[cur]) {
					if (res[child] == res[cur]) {
						cout << "IMPOSSIBLE\n";
						return;
					}
					if (res[child] == 0) {
						res[child] = 3 - res[cur];
						q.push(child);
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) cout << res[i] << " ";
	cout << "\n";
}
int main() {
	cin.tie()->sync_with_stdio(false);
	int n, m, a, b;
	cin >> n >> m;
	vector<vector<int>> route(n + 1);
	while (m--) {
		cin >> a >> b;
		route[a].emplace_back(b);
		route[b].emplace_back(a);
	}
	chaewon(route, n);
	return 0;
}