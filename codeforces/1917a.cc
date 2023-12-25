#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	int t, n, a[105];
	cin >> t;
	while (t--) {
		cin >> n;
		int zeros = 0, negs = 0;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			zeros += a[i] == 0;
			negs += a[i] < 0;
		}
		if (zeros || negs % 2 == 1) { cout << "0\n"; }
		else cout << "1\n1 0\n";
	}
	return 0;
}
