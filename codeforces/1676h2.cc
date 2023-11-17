#include <bits/stdc++.h>
using namespace std;
#define int long long
// Fenwick tree
struct FenwickTree {
		vector<int> bit;
		int n;
		FenwickTree(int n) {
			this->n = n;
			bit.assign(n, 0);
		}
		FenwickTree(vector<int> a)
		  : FenwickTree(a.size()) {
			for (size_t i = 0; i < a.size(); i++) add(i, a[i]);
		}
		int sum(int r) {
			int ret = 0;
			for (; r >= 0; r = (r & (r + 1)) - 1) ret += bit[r];
			return ret;
		}
		int sum(int l, int r) { return sum(r) - sum(l - 1); }
		void add(int idx, int delta) {
			for (; idx < n; idx = idx | (idx + 1))
				bit[idx] += delta;
		}
};
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> a(n + 1);
		for (int i = 1; i <= n; i++) cin >> a[i];
		auto f = FenwickTree(n + 5);
		int res = 0;
		for (int i = 1; i <= n; i++) {
			res += f.sum(a[i], n);
			f.add(a[i], 1);
		}
		cout << res << '\n';
	}
	return 0;
}
