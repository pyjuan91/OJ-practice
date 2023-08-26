#include <bits/stdc++.h>
#define int long long
using namespace std;
map<int, int> mp;
int chaewon(int a, int b) {
	int D = a * a - 4ll * b;
	int sq = sqrt(D);
	if (sq * sq != D) return 0;
	int x1 = (a + sq), x2 = (a - sq);
	if (x1 % 2 || x2 % 2) return 0;
	x1 /= 2, x2 /= 2;
	if (x1 == x2) return mp[x1] * (mp[x1] - 1) / 2;
	return mp[x1] * mp[x2];
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, m, a, b, x;
	cin >> t;
	while (t--) {
		mp.clear();
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> x;
			mp[x]++;
		}
		cin >> m;
		while (m--) {
			cin >> a >> b;
			cout << chaewon(a, b) << ' ';
		}
		cout << '\n';
	}
	return 0;
}
