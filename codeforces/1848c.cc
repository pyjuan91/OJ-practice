#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5 + 5;
int t, n, a[maxn], b[maxn], times;
int become_zero(int a, int b) {
	if (a == 0) return 0;
	if (b == 0) return 1;
	if (a == b) return 2;
	if (a < b) {
		if (a * 2 > b) return 1 + become_zero(b, b - a);
		return 3 * (b / a / 2) + become_zero(a, b % (a * 2));
	}
	if (b * 2 > a) return 1 + become_zero(b, a - b);
	return 3 * (a / b / 2) + become_zero(a % (b * 2), b);
}
bool chaewon() {
	times = -1;
	for (int i = 0; i < n; i++) {
		if (a[i] == 0 && b[i] == 0) continue;
		auto cur = become_zero(a[i], b[i]) % 3;
		if (times == -1) times = cur;
		else if (times != cur) return false;
	}
	return true;
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];
		if (chaewon()) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}