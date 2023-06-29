#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5; // limit for array size
int n, h; // array size
int t[2 * N], d[N];

void apply(int p, int value) {
	t[p] += value;
	if (p < n) d[p] += value;
}

void build(int p) {
	while (p > 1)
		p >>= 1, t[p] = t[p << 1] + t[p << 1 | 1] + d[p];
}

void push(int p) {
	for (int s = h; s > 0; --s) {
		int i = p >> s;
		if (d[i] != 0) {
			apply(i << 1, d[i]);
			apply(i << 1 | 1, d[i]);
			d[i] = 0;
		}
	}
}

void inc(int l, int r, int value) {
	l += n, r += n;
	int l0 = l, r0 = r;
	for (; l < r; l >>= 1, r >>= 1) {
		if (l & 1) apply(l++, value);
		if (r & 1) apply(--r, value);
	}
	build(l0);
	build(r0 - 1);
}

int query(int l, int r) {
	l += n, r += n;
	push(l);
	push(r - 1);
	int res = 0;
	for (; l < r; l >>= 1, r >>= 1) {
		if (l & 1) res += t[l++];
		if (r & 1) res += t[--r];
	}
	return res;
}

int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int q, op, a, b, c;
	cin >> n >> q;
	h = sizeof(int) * 8 - __builtin_clz(n);
	for (int i = 0; i < n; i++) cin >> t[i + n], build(i + n);
	while (q--) {
		cin >> op;
		if (op == 1) cin >> a >> b >> c, inc(a - 1, b, c);
		else cin >> a, cout << query(a - 1, a) << "\n";
	}
	return 0;
}
