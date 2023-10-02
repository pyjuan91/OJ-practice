#include <bits/stdc++.h>
#define int long long
using namespace std;
struct Query {
		int l, r, idx;
		Query(int l, int r, int idx)
		  : l(l)
		  , r(r)
		  , idx(idx) {}
		Query() {}
};

int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int n, m, l, r, res = 0;
	cin >> n >> m;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	vector<Query> q(m);
	vector<int> ans(m);
	for (int i = 0; i < m; i++) {
		cin >> l >> r;
		q[i] = Query(l, r, i);
	}
	const int block = sqrt(n);
	sort(q.begin(), q.end(), [&](const Query& a, const Query& b) {
		if (a.r / block == b.r / block) return a.l < b.l;
		return a.r / block < b.r / block;
	});
	l = 1, r = 0;
	unordered_map<int, int> cnt;
	for (auto x : q) {
		while (r < x.r) {
			r++;
			cnt[a[r]]++;
			if (cnt[a[r]] == a[r]) res++;
			else if (cnt[a[r]] == a[r] + 1) res--;
		}
		while (r > x.r) {
			cnt[a[r]]--;
			if (cnt[a[r]] == a[r]) res++;
			else if (cnt[a[r]] == a[r] - 1) res--;
			r--;
		}
		while (l < x.l) {
			cnt[a[l]]--;
			if (cnt[a[l]] == a[l]) res++;
			else if (cnt[a[l]] == a[l] - 1) res--;
			l++;
		}
		while (l > x.l) {
			l--;
			cnt[a[l]]++;
			if (cnt[a[l]] == a[l]) res++;
			else if (cnt[a[l]] == a[l] + 1) res--;
		}
		ans[x.idx] = res;
	}
	for (auto x : ans) cout << x << '\n';
	return 0;
}
