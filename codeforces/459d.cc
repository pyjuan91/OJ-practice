#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto &x : a) cin >> x;
	vector<int> pre, suf;
	map<int, int> cnt;
	for (int i = 0; i < n; i++) {
		cnt[a[i]]++;
		pre.push_back(cnt[a[i]]);
	}
	cnt.clear();
	for (int i = n - 1; i >= 0; i--) {
		cnt[a[i]]++;
		suf.push_back(cnt[a[i]]);
	}
	reverse(suf.begin(), suf.end());
	vector<int> fenwick_tree(n + 1, 0);
	auto lowbit = [](int x) { return x & (-x); };
	auto add = [&](int x, int d) {
		for (int i = x; i <= n; i += lowbit(i))
			fenwick_tree[i] += d;
	};
	auto query = [&](int x) {
		int res = 0;
		for (int i = x; i; i -= lowbit(i))
			res += fenwick_tree[i];
		return res;
	};
	for (int i = 0; i < n; i++) add(suf[i], 1);
	int res = 0;
	for (int i = 0; i < n - 1; i++) {
		add(suf[i], -1);
		res += query(pre[i] - 1);
	}
	cout << res << '\n';
	return 0;
}
