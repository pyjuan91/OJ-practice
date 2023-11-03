#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<int> a(2 * n);
		for (auto &i : a) cin >> i;
		sort(a.begin(), a.end());
		cout << a[n - 1] - a[0] + a[2 * n - 1] - a[n] << '\n';
		for (int i = 0; i < n; i++)
			cout << a[i] << ' ' << a[i + n] << '\n';
	}
	return 0;
}
