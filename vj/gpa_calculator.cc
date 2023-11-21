#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n;
	cin >> t;
	for (int kase = 1; kase <= t; kase++) {
		cin >> n;
		double sum = 0, x;
		for (int i = 0; i < n; i++) {
			cin >> x;
			sum += x;
		}
		cout << "Case " << kase << ": " << fixed
			 << setprecision(3) << sum / n << '\n';
	}
	return 0;
}
