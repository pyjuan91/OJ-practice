#include <bits/stdc++.h>
#define int long long
using namespace std;
struct road {
		int cost, a, b;
		road(int cost, int a, int b)
		  : cost(cost)
		  , a(a)
		  , b(b) {}
		bool operator<(const road& r) const {
			return cost < r.cost;
		}
		bool operator>(const road& r) const {
			return cost > r.cost;
		}
};
class DisjointSetUnion {
	public:
		vector<int> rank;
		DisjointSetUnion(int n) { rank = vector<int>(n, -1); }
		int find_root(int x) {
			if (rank[x] < 0) return x;
			return rank[x] = find_root(rank[x]);
		}
		int get_size(int x) { return -rank[find_root(x)]; }
		bool unite(int x, int y) {
			x = find_root(x), y = find_root(y);
			if (x == y) return false;
			if (rank[x] > rank[y]) swap(x, y);
			rank[x] += rank[y];
			rank[y] = x;
			return true;
		}
};
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, a, b, c, res = 0;
	cin >> n >> m;
	priority_queue<road, vector<road>, greater<road>> pq;
	while (m--) {
		cin >> a >> b >> c;
		pq.push(road(c, a, b));
	}
	auto dsu = DisjointSetUnion(n + 1);
	while (!pq.empty()) {
		auto r = pq.top();
		pq.pop();
		if (dsu.unite(r.a, r.b)) res += r.cost;
	}
	if (dsu.get_size(1) != n) cout << "IMPOSSIBLE";
	else cout << res;
	return 0;
}