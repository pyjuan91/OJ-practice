#include <bits/stdc++.h>
using namespace std;
struct DisjointSetUnion {
		vector<int> parent_rank;
		DisjointSetUnion(int n) {
			parent_rank = vector<int>(n + 1, -1);
		}
		int find_root(int a) {
			if (parent_rank[a] < 0) return a;
			return parent_rank[a] = find_root(parent_rank[a]);
		}
		bool is_same_union(int a, int b) {
			return find_root(a) == find_root(b);
		}
		int get_union_size(int a) {
			return -parent_rank[find_root(a)];
		}
		bool unite(int a, int b) {
			auto a_root = find_root(a), b_root = find_root(b);
			if (a_root == b_root) return false;
			if (get_union_size(a_root) < get_union_size(b_root))
				swap(a_root, b_root);
			parent_rank[a_root] += parent_rank[b_root];
			parent_rank[b_root] = a_root;
			return true;
		}
};
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, a, b, cc, mcc;
	cin >> n >> m;
	auto dsu = DisjointSetUnion(n);
	cc = n, mcc = 1;
	while (m--) {
		cin >> a >> b;
		if (dsu.unite(a, b)) {
			cc -= 1;
			mcc = max(mcc, dsu.get_union_size(a));
		}
		cout << cc << " " << mcc << "\n";
	}
	return 0;
}