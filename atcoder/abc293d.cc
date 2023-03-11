#include <bits/stdc++.h>
using namespace std;
class DisjointSet {
		map<int, int> parent;


	public:
		int find_root(int x) {
			if (x == parent[x]) return x;
			int root = find_root(parent[x]);
			return parent[x] = parent[-x] = root;
		}
		DisjointSet(size_t n) { init(n); }
		void init(int n) {
			for (size_t i = 0; i <= n; ++i)
				parent[i] = parent[-i] = i;
		}
		bool Same(int a, int b) {
			return find_root(a) == find_root(b);
		}
		void Union(int a, int b) {
			parent[find_root(a)] = find_root(b);
		}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie();
	int n, m, a, b, cyc = 0;
	char ac, bc;
	cin >> n >> m;
	DisjointSet djs(n);
	while (m--) {
		cin >> a >> ac >> b >> bc;
		if (ac == 'R') a = -a;
		if (bc == 'R') b = -b;
		if (djs.Same(a, b)) cyc += 1;
		else djs.Union(a, b);
	}
	unordered_set<int> s;
	for (int i = 1; i <= n; i++)
		s.insert(djs.find_root(i));
	cout << cyc << " " << s.size() - cyc << "\n";
	return 0;
}