#include <bits/stdc++.h>
using namespace std;
const int ma = 1e5 + 5;
vector<vector<int>> adj(ma);
vector<bool> vis(ma, false), in_stack(ma, false);
vector<int> res;
bool chaewon(int cur) {
	in_stack[cur] = vis[cur] = true;
	for (auto child : adj[cur]) {
		if (in_stack[child]) {
			res.emplace_back(child);
			in_stack[child] = false;
			return true;
		}
		else if (!vis[child]) {
			if (chaewon(child)) {
				if (in_stack[child]) {
					res.emplace_back(child);
					in_stack[child] = false;
					return true;
				}
				else {
					res.emplace_back(child);
					return false;
				}
			}
			if (!res.empty()) return false;
		}
	}
	in_stack[cur] = false;
	return false;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m, a, b;
	cin >> n >> m;
	while (m--) {
		cin >> a >> b;
		adj[a].emplace_back(b);
	}
	for (int i = 1; res.empty() && i <= n; i++) chaewon(i);
	if (res.empty()) cout << "IMPOSSIBLE\n";
	else {
        if(res[0] != res.back()) res.emplace_back(res[0]);
        reverse(res.begin(), res.end());
        cout << res.size() << "\n";
		for (int i : res) cout << i << " ";
		cout << "\n";
	}
	return 0;
}