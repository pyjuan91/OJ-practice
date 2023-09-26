#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e5 + 5;
struct Query {
		int l, r, id;
		Query(int l, int r, int id)
		  : l(l)
		  , r(r)
		  , id(id) {}
		Query() {}
};
int n, m, a[maxn], chunk, cnt[1000006] = {}, ans[maxn];
Query q[maxn];
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= m; i++) {
		cin >> q[i].l >> q[i].r;
		q[i].id = i;
	}
	chunk = sqrt(n);
	sort(q + 1, q + m + 1, [](Query a, Query b) {
		if (a.l / chunk == b.l / chunk) return a.r < b.r;
		return a.l < b.l;
	});
	int cur_score = 0, cur_left = 0, cur_right = 0;
	auto add_element = [&](int index) {
		cur_score += (2 * cnt[a[index]] + 1) * a[index];
		cnt[a[index]]++;
	};
	auto remove_element = [&](int index) {
		cur_score += (-2 * cnt[a[index]] + 1) * a[index];
		cnt[a[index]]--;
	};
	for (int i = 1; i <= m; i++) {
		while (cur_left < q[i].l) remove_element(cur_left++);
		while (cur_left > q[i].l) add_element(--cur_left);
		while (cur_right < q[i].r) add_element(++cur_right);
		while (cur_right > q[i].r) remove_element(cur_right--);
		ans[q[i].id] = cur_score;
	}
	for (int i = 1; i <= m; i++) cout << ans[i] << '\n';
	return 0;
}