// #include <bits/stdc++.h>
// using namespace std;
// class DisjointSet {
// 	public:
// 		int n;
// 		vector<int> parent;

// 		DisjointSet() {
// 			n = 0;
// 			parent.clear();
// 		}

// 		DisjointSet(int _n) {
// 			n = _n;
// 			parent.resize(n);
// 			for (int i = 0; i < n; i++) parent[i] = i;
// 		}

// 		int findRoot(int a) {
// 			if (parent[a] == a) return a;
// 			return findRoot(parent[a]);
// 		}

// 		bool isSame(int a, int b) {
// 			return findRoot(parent[a]) == findRoot(parent[b]);
// 		}

// 		void unite(int a, int b) {
// 			parent[a] = findRoot(parent[b]);
// 			parent[b] = parent[a];
// 		}
// };
// int main() {
// 	ios_base::sync_with_stdio(false);
// 	cin.tie();
// 	int n, m, a, b;
// 	cin >> n >> m;
// 	DisjointSet djs(n + 1);
// 	vector<int> e(n + 1, 0);
// 	for (int i = 0; i < m; i++) {
// 		cin >> a >> b;
// 		e[b] += 1;
// 		djs.unite(a, b);
// 	}

// 	map<int, vector<int>> check;
// 	for (int i = 1; i <= n; i++) {
// 		int rt = djs.findRoot(i);
// 		if (!check.count(rt)) {
// 			check[rt].emplace_back(1);
// 			check[rt].emplace_back(e[i]);
// 		}
// 		else {
// 			check[rt][0] += 1;
// 			check[rt][1] += e[i];
// 		}
// 	}
// 	bool y = true;
// 	for (auto p : check) {
// 		if (p.second[0] != p.second[1]) {
// 			y = false;
// 			break;
// 		}
// 	}
// 	if (y) cout << "Yes\n";
// 	else cout << "No\n";
// 	return 0;
// }

#include <bits/stdc++.h>
using namespace std;
void chaewon(
	vector<bool>& used, int& cyc, int prev, int cur,
	vector<vector<int>>& e) {
	used[cur] = true;
	bool pe = true;
	for (auto edge : e[cur]) {
		if (edge == prev && pe) {
			pe = false;
			continue;
		}
		if (used[edge]) cyc += 1;
		else chaewon(used, cyc, cur, edge, e);
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	int n, m, a, b;
	cin >> n >> m;
	vector<vector<int>> e(n + 1);
	vector<bool> used(n + 1, false);
	while (m--) {
		cin >> a >> b;
		e[a].emplace_back(b);
		e[b].emplace_back(a);
	}
	bool y = true;
	for (int i = 1; i <= n; i++) {
		if (used[i]) continue;
		int cyc = 0;
		chaewon(used, cyc, 0, i, e);
		// cout << "i: " << i << " cyc: " << cyc << endl;
		if (cyc != 2) {
			y = false;
			break;
		}
	}
	if (y) cout << "Yes\n";
	else cout << "No\n";
	return 0;
}