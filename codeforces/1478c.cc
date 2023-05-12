#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie()->sync_with_stdio(false);
	int t, n, sum, prefix_sum;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> a(2 * n);
		for (auto &x : a) cin >> x;
		sort(a.begin(), a.end());
		for (int i = 0; i < 2 * n; i += 2) {
			if (a[i] != a[i + 1] || a[i] % 2) {
				cout << "NO\n";
				goto chaewon;
			}
		}
		sum = a[0] / 2;
		prefix_sum = 0;
		for (int i = 2; i < 2 * n; i += 2) {
			if (a[i] == a[i - 2] || ((a[i] - a[i - 2]) % i)) {
				cout << "NO\n";
				goto chaewon;
			}
			// cout << sum << " " << prefix_sum << endl;
			prefix_sum += (a[i] - a[i - 2]) / i;
			sum -= prefix_sum;
			// cout << sum << " " << prefix_sum << endl << endl;
		}
		if (sum <= 0 || (sum % n)) cout << "NO\n";
		else cout << "YES\n";

	chaewon: {}
	}
	return 0;
}