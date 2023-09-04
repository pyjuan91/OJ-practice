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
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, k, x, res = 0;
	cin >> n >> m;
	bool lead_lan = false;
	vector<vector<int>> lan(m + 1);
	for (int i = 1; i <= n; i++) {
		cin >> k;
		if (k) lead_lan = true;
		while (k--) {
			cin >> x;
			lan[x].push_back(i);
		}
	}
	if (lead_lan == false) {
		cout << n << '\n';
		return 0;
	}
	auto ds = dsu(n + 1);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j < lan[i].size(); j++)
			ds.merge(lan[i][0], lan[i][j]);
	}
	auto g = ds.groups();
	cout << g.size() - 2 << '\n';
	return 0;
}
