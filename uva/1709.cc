#include <bits/stdc++.h>
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int p, a, b, c, d, n;
	while (cin >> p) {
		cin >> a >> b >> c >> d >> n;
		double ma = p * (sin(a + b) + cos(c + d) + 2), ma_diff = 0.0;
		for (int i = 2; i <= n; i++) {
			ma_diff = max(
			  ma_diff, ma - p * (sin(a * i + b) + cos(c * i + d) + 2));
			ma = max(ma, p * (sin(a * i + b) + cos(c * i + d) + 2));
		}
		cout << fixed << setprecision(10) << ma_diff << '\n';
	}
	return 0;
}
