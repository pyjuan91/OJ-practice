#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie()->sync_with_stdio(false);
	int t, n, m, k;
	cin >> t;
	while (t--) {
		cin >> n >> m >> k;
		vector<int> c(m);
		for (auto &x : c) cin >> x;
		sort(c.begin(), c.end());
		if (c[m - 1] <= n / k + (n % k > 0) && (m <= n % k || c[m - 1 - n % k] <= n / k))
			cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}