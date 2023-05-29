#include <bits/stdc++.h>
#define int long long
using namespace std;
void chaewon(int a, int b, int c, int d) {
	int pro = a * b;
	for (int x = a + 1; x <= c; x++) {
		int k_fac = pro / __gcd(pro, x);
		auto left_bound = b / k_fac, right_bound = d / k_fac;
		if (right_bound > left_bound) {
			cout << x << " " << k_fac * (left_bound + 1) << "\n";
			return;
		}
	}
	cout << "-1 -1\n";
}
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, a, b, c, d;
	cin >> t;
	while (t--) {
		cin >> a >> b >> c >> d;
		chaewon(a, b, c, d);
	}
	return 0;
}