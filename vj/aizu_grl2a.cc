#include <bits/stdc++.h>
#define int long long
using namespace std;
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
struct Edge {
		int u, v, w;
		bool operator<(Edge const& other) {
			return w < other.w;
		}
		Edge(int u, int v, int w)
		  : u(u)
		  , v(v)
		  , w(w) {}
		Edge() {}
};
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, a, b, c, res = 0;
	cin >> n >> m;
	vector<Edge> edges;
	while (m--) {
		cin >> a >> b >> c;
		edges.push_back(Edge(a, b, c));
	}
	sort(edges.begin(), edges.end());
	auto d = dsu(n);
    for (auto& e : edges) {
        if (!d.same(e.u, e.v)) {
            d.merge(e.u, e.v);
            res += e.w;
        }
    }
    cout << res << '\n';
	return 0;
}
