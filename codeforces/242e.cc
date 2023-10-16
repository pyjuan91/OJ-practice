#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e5 + 5;
int n, q, x, op, l, r;
int seg[25][4 * maxn] = {}, lz[25][4 * maxn] = {};
void pull(int id, int l, int r, int seg_bit) {
	if (lz[seg_bit][id] == 0) return;
	int mid = (l + r) >> 1;
	seg[seg_bit][id << 1] = mid - l + 1 - seg[seg_bit][id << 1];
	lz[seg_bit][id << 1] ^= 1LL;
	seg[seg_bit][id << 1 | 1] = r - mid - seg[seg_bit][id << 1 | 1];
	lz[seg_bit][id << 1 | 1] ^= 1LL;
	lz[seg_bit][id] = 0;
}
void update(int id, int cur_l, int cur_r, int tar_l, int tar_r, int seg_bit) {
	// out of range
	if (cur_l > tar_r || cur_r < tar_l) return;
	// completely in range
	if (cur_l >= tar_l && cur_r <= tar_r) {
		seg[seg_bit][id] = cur_r - cur_l + 1 - seg[seg_bit][id];
		lz[seg_bit][id] ^= 1LL;
		return;
	}
	// partially in range
	pull(id, cur_l, cur_r, seg_bit);
	int mid = (cur_l + cur_r) >> 1;
	update(id << 1, cur_l, mid, tar_l, tar_r, seg_bit);
	update(id << 1 | 1, mid + 1, cur_r, tar_l, tar_r, seg_bit);
	seg[seg_bit][id] = seg[seg_bit][id << 1] + seg[seg_bit][id << 1 | 1];
}
int query(int id, int cur_l, int cur_r, int tar_l, int tar_r, int seg_bit) {
	// out of range
	if (cur_l > tar_r || cur_r < tar_l) return 0;
	// completely in range
	if (cur_l >= tar_l && cur_r <= tar_r)
		return seg[seg_bit][id];
	// partially in range
	pull(id, cur_l, cur_r, seg_bit);
	int mid = (cur_l + cur_r) >> 1;
	return query(id << 1, cur_l, mid, tar_l, tar_r, seg_bit)
		 + query(id << 1 | 1, mid + 1, cur_r, tar_l, tar_r, seg_bit);
}
int qq(int l, int r) {
	int ans = 0;
	for (int i = 0; i < 25; i++) {
		ans += query(1, 1, n, l, r, i) * (1LL << i);
	}
	return ans;
}
void cc(int l, int r, int m) {
	for (int i = 0; i < 25; i++) {
		if (m & (1LL << i)) update(1, 1, n, l, r, i);
	}
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> x, cc(i, i, x);
	cin >> q;
	while (q--) {
		cin >> op >> l >> r;
		if (op == 1) cout << qq(l, r) << '\n';
		else cin >> x, cc(l, r, x);
	}
	return 0;
}