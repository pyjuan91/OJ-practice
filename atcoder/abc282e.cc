#include <bits/stdc++.h>
#define int long long
using namespace std;
int fast_power(int base, int power, int mod) {
	int res = 1;
	while (power) {
		if (power & 1) res = res * base % mod;
		base = base * base % mod;
		power >>= 1;
	}
	return res;
}
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
				[&](const std::vector<int> &v) {
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
	int n, m, res = 0;
	cin >> n >> m;
	vector<int> a(n);
	for (auto &x : a) cin >> x;
	vector<vector<int>> e;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int sc
			  = (fast_power(a[i], a[j], m) + fast_power(a[j], a[i], m)) % m;
			e.push_back({i, j, sc});
		}
	}
	sort(e.begin(), e.end(), [&](auto l, auto r) {
		return l[2] < r[2];
	});
	auto d = dsu(n + 1);
	while (!e.empty()) {
		auto ce = e.back();
		e.pop_back();
		if (d.same(ce[0], ce[1])) continue;
		d.merge(ce[0], ce[1]);
		res += ce[2];
	}
	cout << res << "\n";
	return 0;
}