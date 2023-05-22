#include <bits/stdc++.h>
using namespace std;
class DisjointSet {
	public:
		int n;
		vector<int> parent;
		DisjointSet(int _n) {
			n = _n + 1;
			parent.resize(n);
			for (int i = 0; i < n; i++) parent[i] = i;
		}
		int find_root(int a) {
			if (parent[a] == a) return a;
			return parent[a] = find_root(parent[a]);
		}
		void unite(int a, int b) {
			parent[find_root(a)] = find_root(b);
		}
		bool is_same(int a, int b) {
			return find_root(a) == find_root(b);
		}
};
int main() {
	cin.tie()->sync_with_stdio(false);
	int t, n, x;
	cin >> t;
	while (t--) {
		cin >> n;
		auto djs = DisjointSet(n);
		vector<int> hands(n + 1, 2), shake(n + 1, 0);
		for (int i = 1; i <= n; i++) {
			cin >> x;

			if (shake[x] != i) {
				shake[i] = x;
				hands[x] -= 1;
				hands[i] -= 1;
			}
			djs.unite(i, x);
		}
		map<int, int> m;
		for (int i = 1; i <= n; i++) {
			auto pa = djs.find_root(i);
			m[pa] += hands[i];
		}
		int mi = m.size();
		for (auto p : m) {
			// cout << p.first << " " << p.second << endl;
			if (p.second >= 2) mi -= 1;
		}
		if (mi < m.size()) mi += 1;
		cout << mi << " " << m.size() << "\n";
	}
	return 0;
}