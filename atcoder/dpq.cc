#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 2e5 + 5;
int N, h[maxn], a[maxn];
ll seg[2 * maxn];
ll query(int l, int r) { // sum on interval [l, r]
	ll res = 0;
	for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
		if (l & 1) res = max(res, seg[l++]);
		if (r & 1) res = max(res, seg[--r]);
	}
	return res;
}
void modify(int p, int value) {
	ll prev = query(0, p);
	for (seg[p += N] = prev + value; p > 1; p >>= 1)
		seg[p >> 1] = max(seg[p], seg[p ^ 1]);
}
int main() {
	cin.tie()->sync_with_stdio(false);
	cin >> N;
	ll res = 0;
	for (int i = 0; i < N; i++) cin >> h[i];
	for (int i = 0; i < N; i++) cin >> a[i];
	for (int i = 0; i < N; i++) {
		modify(h[i] - 1, a[i]);
		res = max(res, query(0, h[i]));
	}
	cout << res;
	return 0;
}