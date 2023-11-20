#include <bits/stdc++.h>
#define int long long
using namespace std;
struct Route {
		int a, b, c;
		Route(int a, int b, int c)
		  : a(a)
		  , b(b)
		  , c(c) {}
		Route() {}
		bool operator<(const Route& other) const {
			if (c == other.c) {
				if (a == other.a) return b < other.b;
				return a < other.a;
			}
			return c < other.c;
		}
		bool operator==(const Route& other) const {
			return a == other.a && b == other.b && c == other.c;
		}
};
struct dsu {
	public:
		dsu()
		  : _n(0) {}
		explicit dsu(int n)
		  : _n(n)
		  , parent_or_size(n, -1) {}

		int merge(int a, int b) {
			assert(0 <= a && a < _n);
			assert(0 <= b && b < _n);
			int x = leader(a), y = leader(b);
			if (x == y) return x;
			if (-parent_or_size[x] < -parent_or_size[y])
				std::swap(x, y);
			parent_or_size[x] += parent_or_size[y];
			parent_or_size[y] = x;
			return x;
		}

		bool same(int a, int b) {
			assert(0 <= a && a < _n);
			assert(0 <= b && b < _n);
			return leader(a) == leader(b);
		}

		int leader(int a) {
			assert(0 <= a && a < _n);
			if (parent_or_size[a] < 0) return a;
			return parent_or_size[a] = leader(parent_or_size[a]);
		}

		int size(int a) {
			assert(0 <= a && a < _n);
			return -parent_or_size[leader(a)];
		}

		std::vector<std::vector<int>> groups() {
			std::vector<int> leader_buf(_n), group_size(_n);
			for (int i = 0; i < _n; i++) {
				leader_buf[i] = leader(i);
				group_size[leader_buf[i]]++;
			}
			std::vector<std::vector<int>> result(_n);
			for (int i = 0; i < _n; i++) {
				result[i].reserve(group_size[i]);
			}
			for (int i = 0; i < _n; i++) {
				result[leader_buf[i]].push_back(i);
			}
			result.erase(
			  std::remove_if(
				result.begin(), result.end(),
				[&](const std::vector<int>& v) {
				return v.empty();
			}),
			  result.end());
			return result;
		}

	private:
		int _n;
		// root node: -1 * component size
		// otherwise: parent
		std::vector<int> parent_or_size;
};
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, k, m, a, b, c;
	bool first = true;
	while (cin >> n) {
		if (first) first = false;
		else cout << "\n";
		set<Route> routes;
		vector<Route> neo_routes;
		for (int i = 1; i < n; i++) {
			cin >> a >> b >> c;
			if (a == b) continue;
			if (a > b) swap(a, b);
			routes.insert(Route(a, b, c));
		}
		cin >> k;
		for (int i = 0; i < k; i++) {
			cin >> a >> b >> c;
			if (a == b) continue;
			if (a > b) swap(a, b);
			neo_routes.push_back(Route(a, b, c));
		}
		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> a >> b >> c;
			if (a == b) continue;
			if (a > b) swap(a, b);
			routes.insert(Route(a, b, c));
		}
		dsu d(n + 1);
		int edge_cnt = 0, first_ans = 0;
		for (auto r : routes) {
			if (d.same(r.a, r.b)) continue;
			d.merge(r.a, r.b);
			first_ans += r.c;
			edge_cnt++;
			if (edge_cnt == n - 1) break;
		}
		d = dsu(n + 1), edge_cnt = 0;
		int second_ans = 0;
		for (auto r : neo_routes) routes.insert(r);
		for (auto r : routes) {
			if (d.same(r.a, r.b)) continue;
			d.merge(r.a, r.b);
			second_ans += r.c;
			edge_cnt++;
			if (edge_cnt == n - 1) break;
		}
		cout << first_ans << "\n" << second_ans << '\n';
	}
	return 0;
}
