#include <bits/stdc++.h>
using namespace std;
void chaewon(int cur, auto& adj, auto& res, auto& put_in) {
	while (!adj[cur].empty()) {
		int nxt = adj[cur].back();
		adj[cur].pop_back();
		if (!put_in[nxt]) {
			chaewon(nxt, adj, res, put_in);
			res.push_back(nxt);
			put_in[nxt] = true;
		}
	}
}
int main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, x;
	cin >> n;
	vector<vector<int>> adj(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> m;
		while (m--) {
			cin >> x;
			adj[i].push_back(x);
		}
	}
	vector<int> res;
	vector<bool> put_in(n + 1, false);
	chaewon(1, adj, res, put_in);
    for(auto x: res) cout << x << ' ';
	return 0;
}