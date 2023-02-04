#include <bits/stdc++.h>
using namespace std;
class DisjointSet {
	public:
		int n;
		vector<int> parent;
		DisjointSet() {
			n = 0;
			parent.clear();
		}
		DisjointSet(int _n) {
			n = _n;
			parent.resize(n + 1);
			for (int i = 1; i <= n; i++) parent[i] = i;
		}
		int findRoot(int a) {
			if (parent[a] == a) return a;
			return parent[a] = findRoot(parent[a]);
		}
		bool isSameUnion(int a, int b) {
			return findRoot(parent[a]) == findRoot(parent[b]);
		}
		void Unite(int a, int b) {
			parent[findRoot(a)] = parent[b];
		}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	int n, m, res = 0, a, b;
	cin >> n >> m;
	DisjointSet djs(n);
	while (m--) {
		cin >> a >> b;
		if (djs.isSameUnion(a, b)) {
			res += 1;
			continue;
		}
		djs.Unite(a, b);
	}
    cout << res;
	return 0;
}