#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	double r;
	cin >> t;
	for (int kase = 1; kase <= t; kase++) {
		cin >> r;
		double ans = 2 * r * r * 3.1416;
		ans = 8 * r * r - ans;
		cout << "Case " << kase << ": " << fixed
			 << setprecision(2) << ans << '\n';
	}
	return 0;
}
