#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	int n, q, cmd, u, v, current;
	cin >> n >> q;
	vector<set<int>> e(n + 1);
	current = n;
	while (q--) {
		cin >> cmd >> u;
		if (cmd == 1) {
			cin >> v;
			e[u].insert(v);
			e[v].insert(u);
			if (e[u].size() == 1) current -= 1;
			if (e[v].size() == 1) current -= 1;
		}
		else {
			for (auto& x : e[u]) {
				e[x].erase(e[x].find(u));
				if (e[x].empty()) current += 1;
			}
			if (e[u].empty()) current -= 1;
			e[u].clear();
			current += 1;
		}
		cout << current << "\n";
	}
	return 0;
}