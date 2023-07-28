#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
int a[maxn], l[maxn], r[maxn], modi[maxn], prefix[maxn];
int t, n, m, q;

void go(int mid) {
	for (int i = 1; i <= n; i++) a[i] = 0;
	for (int i = 1; i <= mid; i++) a[modi[i]] = 1;
}

void cal_pre() {
	prefix[0] = 0;
	for (int i = 1; i <= n; i++)
		prefix[i] = prefix[i - 1] + a[i];
}

bool check() {
	for (int i = 0; i < m; i++) {
		if ((prefix[r[i]] - prefix[l[i] - 1]) * 2 > (r[i] - l[i] + 1))
			return true;
	}
	return false;
}

int chaewon() {
	int left = 0, right = q;
	while (left + 1 < right) {
		int mid = left + (right - left) / 2;
		go(mid);
		cal_pre();
		if (check()) right = mid;
		else left = mid;
	}
	go(right);
	cal_pre();
	return check() ? right : -1;
}

int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < m; i++) cin >> l[i] >> r[i];
		cin >> q;
		for (int i = 1; i <= q; i++) cin >> modi[i];
		cout << chaewon() << "\n";
	}
	return 0;
}
