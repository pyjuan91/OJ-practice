#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5; // limit for array size
int n; // array size
int t[2 * N];

void build() { // build the tree
	for (int i = n - 1; i > 0; --i)
		t[i] = min(t[i << 1], t[i << 1 | 1]);
}

void modify(int p, int value) { // set value at position p
	for (t[p += n] = value; p > 1; p >>= 1)
		t[p >> 1] = min(t[p], t[p ^ 1]);
}

int query(int l, int r) { // sum on interval [l, r)
	int res = INT64_MAX;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1) res = min(res, t[l++]);
		if (r & 1) res = min(res, t[--r]);
	}
	return res;
}

int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int q, op, a, b;
	cin >> n >> q;
	for (int i = 0; i < n; i++) cin >> t[i + n];
	build();
	while (q--) {
		cin >> op >> a >> b;
		if (op == 1) modify(a - 1, b);
		else cout << query(a - 1, b) << "\n";
	}
	return 0;
}