#include <bits/stdc++.h>
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
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m1, m2, a, b;
	vector<pair<int, int>> res;
	cin >> n >> m1 >> m2;
	auto t1 = dsu(n), t2 = dsu(n);
	for (int i = 0; i < m1; i++) {
		cin >> a >> b;
		t1.merge(a - 1, b - 1);
	}
	for (int i = 0; i < m2; i++) {
		cin >> a >> b;
		t2.merge(a - 1, b - 1);
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (t1.same(i, j) || t2.same(i, j)) continue;
			t1.merge(i, j);
			t2.merge(i, j);
			res.emplace_back(make_pair(i + 1, j + 1));
		}
	}
	cout << res.size() << '\n';
	for (auto x : res)
		cout << x.first << ' ' << x.second << '\n';
	return 0;
}
